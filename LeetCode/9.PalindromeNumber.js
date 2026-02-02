/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function (x) {
    let revX = parseInt(x.toString().split("").reverse().join(""));
    if (x === revX) return true;
    else return false;
};
