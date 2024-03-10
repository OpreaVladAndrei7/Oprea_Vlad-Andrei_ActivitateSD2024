using System;
using System.CodeDom;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace curs3
{
    internal class Salariat : ICloneable
    {
        string nume;
        int no;
        float so;

        public Salariat()
        {     //constructor implicit
            nume = "Anonim";
            no = 0;
            so = 1;
        }
        public string Nume
        {
            get { return nume; }
            set { nume = value; }
        }

        public float Salariul => no * so;

        public int Numar_ore
        {
            get => no;
            set
            {
                if (value < 0) throw new Exception("ERR: Numar ore NEGATIV!");
                no = value;
            }
        }

        public float Salariul_orar
        {
            get => so;
            set => so = value;
        }

        public object Clone()
        {
            return new Salariat()
            {
                Nume = this.Nume,
                Numar_ore = this.Numar_ore,
                Salariul_orar = this.Salariul_orar
            };
        }

        public override string ToString() => $"Salariatul {Nume} are salariul {Salariul}";

        public static Salariat operator++( Salariat s)
        {
            s.no++;
            return s; 
        }
        public char this[int k] => nume[k];

        /*public override string ToString()
       {
           return "Nume: " + Nume 
               + "\nNumar de ore: " + Numar_ore 
               + "\nSalariu pe ora: " + Salariul_orar 
               + " \nSalariu total: " + Salariul 
               + '\n';
       }*/
    }
}
