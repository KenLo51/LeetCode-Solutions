double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    unsigned int totalSize = nums1Size + nums2Size;
    unsigned int medianIdx = totalSize / 2 + 1;
    unsigned int nums1Idx = 0;
    unsigned int nums2Idx = 0;
    
    int lastVal[2] = {0, 0};
    for(unsigned int currIdx=0; currIdx<medianIdx; currIdx++){
        if(nums1Idx < nums1Size && nums2Idx < nums2Size){
            if(nums1[nums1Idx] < nums2[nums2Idx]){
                lastVal[1] = lastVal[0];
                lastVal[0] = nums1[nums1Idx];
                nums1Idx = nums1Idx + 1;
            }
            else{
                lastVal[1] = lastVal[0];
                lastVal[0] = nums2[nums2Idx];
                nums2Idx = nums2Idx + 1;
            }
            continue;
        }
        
        if(nums1Idx < nums1Size && nums2Idx >= nums2Size){
            lastVal[1] = lastVal[0];
            lastVal[0] = nums1[nums1Idx];
            nums1Idx = nums1Idx + 1;
            continue;
        }
        if(nums1Idx >= nums1Size && nums2Idx < nums2Size){
            lastVal[1] = lastVal[0];
            lastVal[0] = nums2[nums2Idx];
            nums2Idx = nums2Idx + 1;
            continue;
        }
    }
    
    double median;
    if(totalSize % 2 == 0)
        median = (double)(lastVal[0] + lastVal[1]) / 2.0;
    else
        median = lastVal[0];

    return median;
}
