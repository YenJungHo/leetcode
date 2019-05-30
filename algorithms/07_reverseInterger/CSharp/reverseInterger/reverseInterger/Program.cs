using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace reverseInterger
{
    class Program
    {
        public class Solution
        {
            public int Reverse(int x)
            {
                int rev = 0;
                int MaxValDiv10 = Int32.MaxValue / 10;
                int MinValDiv10 = Int32.MinValue / 10;
                while (x != 0)
                {
                    int pop = x % 10;
                    x /= 10;
                    if (rev > MaxValDiv10 || (rev == MaxValDiv10 && pop == 7))
                        return 0;

                    if (rev < MinValDiv10 || (rev == MinValDiv10 && pop == -8))
                        return 0;

                    rev = 10 * rev + pop;
                }

                return rev;
            }
        }
        static void Main(string[] args)
        {
            Solution sol = new Solution();
            int res = sol.Reverse(123456);
            Console.WriteLine(res);
            Console.Read();
        }
    }
}
