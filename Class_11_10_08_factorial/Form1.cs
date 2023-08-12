using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Class_11_10_08_factorial
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_MouseClick(object sender, MouseEventArgs e)
        {
            int fact = 1;
            int n = int.Parse(textBox1.Text);
            for(int i = 1; i<= n; i++)
            {
                fact *= i;
            }
            label2.Text = n + "! =" + fact;
        }
    }
}
