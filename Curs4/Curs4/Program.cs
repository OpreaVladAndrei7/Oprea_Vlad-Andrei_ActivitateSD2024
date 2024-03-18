using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.VisualStyles;

namespace Curs4
{   
    class F_mea:Form
    {
        Button btn;
        public F_mea()
        {
            this.Text = "Prima Aplicatie WF";
            
            btn = new Button();
            btn.Text= "Apasa!";
            btn.Location = new System.Drawing.Point(10,10);

            btn.Click += Btn_Click; 
            this.Controls.Add(btn);
        }

        private void Btn_Click(object sender, EventArgs e)
        {
            Button button = (Button)sender;
            MessageBox.Show("Ai apasat butonul  " + button.Text);
        }
    }
    internal class Program
    {
        static void Main(string[] args)
        {
            Application.Run(new F_mea());
        }
    }
}
