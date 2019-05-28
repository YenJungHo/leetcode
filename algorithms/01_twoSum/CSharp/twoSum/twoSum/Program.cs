using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace twoSum
{
    class Program
    {
        public class Solution
        {
            public int[] TwoSum(int[] nums, int target)
            {
                Dictionary<int, int> map = new Dictionary<int, int>();

                for (int i = 0; i < nums.Length; i++)
                {
                    int Val = target - nums[i];

                    if (map.ContainsKey(Val) == true)
                    {
                        return new int[] { i, map[Val] };
                    }

                    if (map.ContainsKey(nums[i]) == false)
                    {
                        map.Add(nums[i], i);
                    }

                }
                return null;
            }
        }
        static void Main(string[] args)
        {
            return;
        }
    }
}
