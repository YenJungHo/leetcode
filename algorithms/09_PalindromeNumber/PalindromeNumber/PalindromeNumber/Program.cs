using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PalindromeNumber
{
	class Program
	{
		static void Main( string[] args )
		{
			Solution sol = new Solution();
			bool res = sol.IsPalindrome( 121 );
			Console.WriteLine( res );
			Console.Read();

		}
	}
}
