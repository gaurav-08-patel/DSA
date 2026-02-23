/**
 * @param {string} string
 * @return {number}
 */
var lengthOfLastWord = function (string) {
    let lastWord = string.trim().split(" ").reverse()[0];

    return lastWord.length;
};
