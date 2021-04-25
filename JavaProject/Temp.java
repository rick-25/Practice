import java.util.*;


public class Temp {

    public static void main(String[] args) {

        //todo: test

        var test = "";

        Solution obj = new Solution();

        var ans = obj.removeDuplicates(test, 2);

        System.out.println(ans);
    }

}

class Solution {

    public int fourSumCount(int[] nums1, int[] nums2, int[] nums3, int[] nums4) {
        Map<Integer, Integer> sum12 = generateSum(nums1, nums2);
        Map<Integer, Integer> sum34 = generateSum(nums3, nums4);
        
        int count = 0;

        Set<Integer> keys = sum12.keySet();

        Iterator<Integer> it = keys.iterator();
        while(it.hasNext()) {
            int currentKey = it.next();
            if(sum34.containsKey(-currentKey)) {
                count += sum12.get(currentKey) * sum34.get(-currentKey);
            }
        }


        return count;
    }

    private Map<Integer, Integer> generateSum(int[] arr1, int[] arr2) {

        Map<Integer, Integer> sum = new HashMap<Integer, Integer>();

        for(int i : arr1) {
            for(int j : arr2) {
                sum.put((i+j), sum.getOrDefault((i+j), 0) + 1);
            }
        }

        return sum;
    }
}
