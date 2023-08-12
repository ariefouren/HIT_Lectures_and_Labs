using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Class_11_ex_02_finantial_calc
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void button1_MouseClick(object sender, MouseEventArgs e)
        {
            double rate = double.Parse(textBox1.Text) / 12 / 100;
            int nper = int.Parse(textBox2.Text);
            double pmt = double.Parse(textBox3.Text);

            if(radioButton1.Checked) // Calculate PF
            {
                double pv =
                    pmt * (1 - Math.Pow((1 + rate), -nper)) / rate;
                label4.Text = "PV = " + pv.ToString("###,###,###.00");
            }
            else // calculate FV
            {
                double fv = 
                    pmt * (Math.Pow((1 + rate), nper) - 1) / rate;
                label4.Text = "FV = " + fv.ToString("###,###,###.00");
            }
            
        }
    }
}
