using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RomanToInterger
{
	class Program
	{
		static void Main( string[] args )
		{
			Solution sol = new Solution();
			string str = "MDCXCV";
			int res = sol.RomanToInt( str );
			Console.WriteLine( res );
			Console.Read();
		}
	}
}
