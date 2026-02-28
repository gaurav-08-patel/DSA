/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function (nums1, nums2) {
    let mergedArr = [...nums1, ...nums2];
    let sortedArr = mergedArr.sort((a, b) => a - b);

    if (sortedArr.length % 2 === 0) {
        let median =
            (sortedArr[sortedArr.length / 2 - 1] +
                sortedArr[sortedArr.length / 2]) /
            2;
        return median; 
    } else {
        return sortedArr[(sortedArr.length - 1) / 2];
    }
};
