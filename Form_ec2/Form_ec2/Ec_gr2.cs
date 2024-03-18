using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ecg2
{   
    class DeltaException : Exception
    {
        int delta;
        public DeltaException(int delta, string fmesaj): base(fmesaj) {
        this.delta = delta;
        }
    }
    internal class Ec_gr2
    {
        int a, b, c; //coeficienti

        public Ec_gr2()
        {
            a = 1;
            b = c = 0;
        }

        public int coef_x2
        {
            //get { return a; }
            get => a; // operatorul lambda
            set
            {
                if (value == 0)
                {
                    throw new Exception("Coeficientul lui x^2 nu poate fi nul!");
                }
                else a = value;
            }
        }

        public int coef_x
        {
            //get { return b; }
            get => b;
            //set { b = value; }
            set => b = value;
        }

        public int coef_tl
        {
            //get { return c; }
            get => c;
            //set { c = value; }
            set => c = value;
        }

        /*public double delta
		{
			get { return (b * b - 4 * a * c); }
		}*/
        public double delta => b * b - 4 * a * c;

        /*public double radacina1
        {
			get 
			{
				if (delta < 0)
					throw new Exception("Delta este negativ - nu exista radacini reale!");
				else
					return ( (-b + Math.Sqrt(delta)) / (2 * a) ); 
			}
		}*/
        public double radacina1 => (delta < 0) ? throw new Exception("Delta este negativ - nu exista radacini reale!") : (-b + Math.Sqrt(delta)) / (2 * a);

        public double radacina2
        {
            get
            {
                if (delta < 0)
                    throw new Exception("Delta este negativ - nu exista radacini reale!");
                else
                    return ((-b - Math.Sqrt(delta)) / (2 * a));
            }
        }
    }
}