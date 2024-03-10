using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace Project2
{
    struct Element
    {
        int intreg;
        public Element(int intreg)
        {
            this.intreg = intreg;
        }
        public static Element operator++(Element elem)
        {
            elem.intreg++;
            return elem;
        }
        public override string ToString()
        {
            return this.intreg.ToString();
        }
    }
}
