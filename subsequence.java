class Solution {
    private void generateSubsets(int[] nums, int index, int s, int sum, List<Integer> current, List<List<Integer>> result) {
        // Base case: all elements have been considered
        if (index == nums.length) {
          if ( s == sum ) { // For sum
            result.add(new ArrayList<>(current)); // save a copy of current subset
            return;
          }
        }

        // Include the current element
        current.add(nums[index]);
        s += nums[index];// For sum
        generateSubsets(nums, index + 1, s, sum, current, result);

        // Backtrack: remove the last element added
        current.remove(current.size() - 1);
        s -= nums[index]; // For sum
        // Exclude the current element
        generateSubsets(nums, index + 1, s, sum, current, result);
    }

    public List<List<Integer>> subsets(int[] nums, int sum) {
        List<List<Integer>> result = new ArrayList<>();
        generateSubsets(nums, 0, 0, sum, new ArrayList<>(), result);
        return result;
    }
}
##3###############################################################################
class Solution {
   boolean flag = false;
    private void generateSubsets(int[] nums, int index, int s, int sum, List<Integer> current, List<List<Integer>> result) {
        // Base case: all elements have been considered
        if (index == nums.length) {
          if ( s == sum && flag == false) { // For sum
            flag = true;
            result.add(new ArrayList<>(current)); // save a copy of current subset
            return;
          }
        }

        // Include the current element
        current.add(nums[index]);
        s += nums[index];// For sum
        generateSubsets(nums, index + 1, s, sum, current, result);

        // Backtrack: remove the last element added
        current.remove(current.size() - 1);
        s -= nums[index]; // For sum
        // Exclude the current element
        generateSubsets(nums, index + 1, s, sum, current, result);
    }

    public List<List<Integer>> subsets(int[] nums, int sum) {
        List<List<Integer>> result = new ArrayList<>();
        generateSubsets(nums, 0, 0, sum, new ArrayList<>(), result);
        return result;
    }
}
