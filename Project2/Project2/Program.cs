using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Element elem1 = new Element(5);
            Element elem2 = elem1++;
            Console.WriteLine(elem1);
            Console.WriteLine(elem2);
        }
    }
}
