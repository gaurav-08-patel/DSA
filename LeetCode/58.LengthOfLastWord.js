/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function (s) {
    let lastWord = s.trim().split(" ").reverse()[0];

    return lastWord.length;
};
