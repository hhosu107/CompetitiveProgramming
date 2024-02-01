class Solution:
    def minimizeArrayValue(self, nums: List[int]) -> int:
        # sol)
        # For the remaining prefix [a0, .., a_k-2], decrease a_k-1 as:
        # the minimum value that satisfies sum(a_0, ..., a_k-2) <= (k-1) * a_k-1, that is, sum(a_0, ..., a_k-1) <= k * a_k-1.
        # since sum(a_0, ..., a_k-1) is fixed, we can calculate the minimum value.
        # If a_k-1 already doesn't satisfies this, stop.
        ret_max = 0
        prefix_sum = [nums[0]]
        for val in nums[1:]:
            prefix_sum.append(prefix_sum[-1] + val)
        for idx in range(len(nums) - 1, 0, -1):
            pair_sum = nums[idx - 1] + nums[idx]
            target_prefix_sum = prefix_sum[idx]
            if target_prefix_sum % (idx + 1) != 0:
                target_number = (target_prefix_sum // (idx + 1)) + 1
            else:
                target_number = target_prefix_sum // (idx + 1)
            if target_number >= nums[idx]:
                continue
            nums[idx - 1], nums[idx] = pair_sum - target_number, target_number
            prefix_sum[idx - 1] = prefix_sum[idx] - target_number
        for val in nums:
            ret_max = val if ret_max < val else ret_max
        return ret_max
