class Solution {
public:
    string expr;
    int pos;

    set<string> parseConcat() {
        set<string> result;
        result.insert(""); // start with the "empty" concatenation unit

        while (pos < (int)expr.size() && expr[pos] != ',' && expr[pos] != '}') {
            set<string> factor;

            if (expr[pos] == '{') {
                factor = parseUnion();
            } else {
                // read a run of consecutive lowercase letters as one literal token
                string literal;
                while (pos < (int)expr.size() && islower(expr[pos])) {
                    literal += expr[pos];
                    pos++;
                }
                factor.insert(literal);
            }

            // cartesian product: concatenate every string in result with every string in factor
            set<string> newResult;
            for (const string &a : result) {
                for (const string &b : factor) {
                    newResult.insert(a + b);
                }
            }
            result = newResult;
        }

        return result;
    }

    set<string> parseUnion() {
        // assumes expr[pos] == '{'
        pos++; // consume '{'
        set<string> result;

        while (true) {
            set<string> part = parseConcat();
            result.insert(part.begin(), part.end());

            if (pos < (int)expr.size() && expr[pos] == ',') {
                pos++; // consume ',' and parse next part
            } else {
                break;
            }
        }

        pos++; // consume '}'
        return result;
    }

    vector<string> braceExpansionII(string expression) {
        expr = expression;
        pos = 0;
        set<string> result = parseConcat();
        return vector<string>(result.begin(), result.end());
    }
};