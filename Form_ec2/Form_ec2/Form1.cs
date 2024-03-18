using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using ecg2;

namespace Form_ec2
{
    public partial class Form1 : Form
    {   
        Ec_gr2 obec;
        public Form1()
        {
            InitializeComponent();
            obec = new Ec_gr2();
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            obec.coef_x2 = Int32.Parse(cx2.Text);
            obec.coef_x = Int32.Parse(cx.Text);
            obec.coef_tl = Int32.Parse(tl.Text);

            r1.Text = obec.radacina1.ToString("0.##");
            r2.Text = obec.radacina2.ToString("0.##");
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            cx2.Text = obec.coef_x2.ToString();
            cx.Text = obec.coef_x.ToString();
            tl.Text = obec.coef_tl.ToString();
        }
    }
}
