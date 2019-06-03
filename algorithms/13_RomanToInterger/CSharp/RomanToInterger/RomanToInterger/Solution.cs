using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RomanToInterger
{
	class Solution
	{
		// roman number data structure
		struct RomanNum {
			public int nSeq;
			public int nValue;
		}

		// hash table
		private Dictionary<char, RomanNum> m_romanNumMap;

		public Solution()
		// constructor
		{
			m_romanNumMap = new Dictionary<char, RomanNum>();
			m_romanNumMap.Add( 'I', new RomanNum() { nSeq = 0, nValue = 1 } );
			m_romanNumMap.Add( 'V', new RomanNum() { nSeq = 1, nValue = 5 } );
			m_romanNumMap.Add( 'X', new RomanNum() { nSeq = 2, nValue = 10 } );
			m_romanNumMap.Add( 'L', new RomanNum() { nSeq = 3, nValue = 50 } );
			m_romanNumMap.Add( 'C', new RomanNum() { nSeq = 4, nValue = 100 } );
			m_romanNumMap.Add( 'D', new RomanNum() { nSeq = 5, nValue = 500 } );
			m_romanNumMap.Add( 'M', new RomanNum() { nSeq = 6, nValue = 1000 } );
		}

		public int RomanToInt( string s )
		// calculate roman number to interger
		{
			int res = 0;
			RomanNum left, right;
			for( int i = 0; i < s.Length; i++ ) {
				left = m_romanNumMap[ s[ i ] ];

				if( i + 1 < s.Length ) {
					right = m_romanNumMap[ s[ i + 1 ] ];
				}
				else {
					right.nSeq = -1;
					right.nValue = 0;
				}

				if( left.nSeq < right.nSeq ) {
					res = res + right.nValue - left.nValue;
					i++;
				}
				else {
					res = res + left.nValue;
				}
			}
			return res;
		}
	}
}
