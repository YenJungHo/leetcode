using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PalindromeNumber
{
	public class Solution
	{
		public bool IsPalindrome( int x )
		{
			if( x < 0 || ( ( x % 10 == 0 ) && ( x != 0 ) ) ) {
				return false;
			}
			int bak = x;

			int reverse = 0;
			int pop = 0;
			while( x != 0 ) {
				pop = x % 10;
				x /= 10;
				reverse = reverse * 10 + pop;
			}

			return reverse == bak;
		}
	}
}
