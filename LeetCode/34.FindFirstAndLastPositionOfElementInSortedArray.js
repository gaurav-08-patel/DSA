/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function (nums, target) {
    if (!nums.includes(target)) {
        return [-1, -1];
    }
    let range = [];

    nums.some((num) => {
        if (num === target) {
            range.push(nums.indexOf(num));
            return true;
        }
    });

    nums.reverse().some((num) => {
        if (num === target) {
            range.push(nums.length - nums.indexOf(num) - 1);
            return true;
        }
    });

    return range;
};
