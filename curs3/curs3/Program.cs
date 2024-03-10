using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace curs3
{
    internal class Program
    {
        /*
        static float medie(int[] v, int n)
        {
          int s = 0;
          for (int i = 0; i < n; i++)
        {
           s += v[i];
        }

           return s / (float)n;
        } */



        /* static void medie(int[] v, int n, out float med)
         {
             int s = 0;
             for (int i = 0; i < n; i++)
             {
                 s += v[i];
             }

             med = s / (float)n;
         } */



        static float media(params int[] v)
        {
            int s = 0, i;
            for (i = 0; i < v.Length; i++) s += v[i];
            return s / (float)v.Length;
        }

        // delegate int fopa(int x, int y);     //echivalent cu Func<...>

        static int mul(int x, int y) => x * y;

        static void Main(string[] args)
        {
            //int a = 100, b = 7;
            //// fopa obiect = new fopa((v, t) => v + t);
            //Func<int, int, int> obiect = new Func<int, int, int>((v, t) => v + t);
            //Console.WriteLine(obiect(a, b));

            //obiect += mul;
            //Console.WriteLine(obiect(a, b));


            ////foreach(fopa item in obiect.GetInvocationList()) 
            ////{
            ////    Console.WriteLine(item(a, b)); 
            ////}
            //foreach (Func<int, int, int> i in obiect.GetInvocationList())
            //{
            //    Console.WriteLine(i(a, b));
            //}

            //List<object> list = new List<object>();
            //list.Add(200);
            //list.Add("Salut!");
            //list.Add(300);
            //int s = 0;
            //foreach(object item in list) {
            //  if(item is int)  s += (int)item;
            //}
            //Console.WriteLine(s);

            //int a = 100;
            //object o;
            //o = a;
            //Console.WriteLine(a);
            //Console.WriteLine(o);
            //a = 234;
            //Console.WriteLine(a);
            //Console.WriteLine(o);

            //a = (int)o;
            //Console.WriteLine(a);
            //Console.WriteLine(o);
            //// data valorica
            //int ne;

            //// //data referentiala
            //int[] ve = new int[100]; //nu am ce face cu el, trebuie alocata memorie
            //float rez=0;          
            ////int[] v = new int[100];
            //// List<int> v= new List<int>();
            //string aux;
            //Console.Write("Dati nr elem: ");
            //aux = Console.ReadLine();
            //ne = Int32.Parse(aux);
            //for (i = 0; i < 3; i++)
            //{
            //    Console.Write("Dati elem " + i.ToString() + ": ");
            //    ve[i]=Int32.Parse(Console.ReadLine());
            // aux = Console.ReadLine();
            //v[i] = Int32.Parse(aux);
            //ve.Add(Int32.Parse(aux));
            // }
            // foreach (int i in v) Console.WriteLine(i);
            //  media(ve, ne, ref rez);
            //Console.WriteLine("Media = {0:#.##} ", media(12, 45, 22, 67));

            Salariat s1 = new Salariat() { Nume = "Ionescu", Numar_ore = 10, Salariul_orar = 1F };
            Salariat s2 = s1.Clone() as Salariat;
            Console.WriteLine(s1);
            s1++;
            Console.WriteLine(s1);
            Console.WriteLine(s2);
            Console.WriteLine(s1[0]);
            //Console.Write("Introduceti numarul de ore: ");
            //try
            //{
            //    int nr_ore = Int32.Parse(Console.ReadLine());
            //    s1.Numar_ore = nr_ore;
            //    Console.WriteLine(s1);
            //}
            //catch (FormatException ex)
            //{
            //    Console.WriteLine("Eoare de formatare " + ex.Message);
            //}

            //catch (Exception ex)
            //{
            //    Console.WriteLine(ex.Message);
            //}

        }
    }
}
