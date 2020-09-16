# Sorting Algorithms

 Sorting is ordering a list of objects


## What's Included

### O(n<sup>2</sup>) algorithms

- [Bubble sort](/Sorting/Bubble_Sort.c) works by comparing each item in the list with the item next to it, and swapping them if required. In other words, the largest element has bubbled to the top of the array. The algorithm repeats this process until it makes a pass all the way through the list without swapping any items.

- [Insertion sort](/Sorting/Insertion_Sort.c) loops over positions in the array, starting with index 0. Each new position is like the new card handed to you by the dealer, and you need to insert it into the correct place in the sorted subarray to the left of that position.

- [Selection sort](/Sorting/Selection_Sort.c) works as follows - you look through the entire array for the smallest element, once you find it you swap it (the smallest element) with the first element of the array. Then you look for the smallest element in the remaining array (an array without the first element) and swap it with the second element and so on.

- Comparison between O(n<sup>2</sup>) algorithms

   ![O(n^2)_compare_graph](https://user-images.githubusercontent.com/47852407/92424063-e3f88d80-f1a0-11ea-820d-38543fc792df.png)

### O(n*logn) algorithms

- [Merge Sort](/Sorting/Merge_Sort.c) is based on the divide-and-conquer technique. It involves the following three steps - Divide the array into two subarrays (DIVIDE), sort each subarray (CONQUER) and Merge them into one (MERGE). [Merge sort with a different approach](/Sorting/MergeSort_Diff.c)

- [Quick Sort](/Sorting/Quick_Sort.c) is based on the divide-and-conquer technique. DIVIDE by choosing any element in the subarray array. Call this element the pivote. Here we are choosing the rightmost element in the subarray as the pivot. CONQUER by recursively sorting the subarrays of array. COMBINE by doing nothing. Once the conquer step recursively sorts, we are done.
  
