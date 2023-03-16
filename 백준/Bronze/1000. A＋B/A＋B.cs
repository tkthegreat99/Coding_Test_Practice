using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {

            string[] s;
            //Split은 배열을 반환

            
            s = Console.ReadLine().Split();

            Console.WriteLine(int.Parse(s[0]) +  int.Parse(s[1]));
           
           
            




        }
    }
}
