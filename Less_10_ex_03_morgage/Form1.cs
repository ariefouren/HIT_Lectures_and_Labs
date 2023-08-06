using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Less_10_ex_03_morgage
{
    public partial class mortgage_calc : Form
    {
        enum CalcType {FV, PV};
        private CalcType type = CalcType.FV;


        public mortgage_calc()
        {
            InitializeComponent();
        }

        private void radioButtonPV_CheckedChanged(object sender, EventArgs e)
        {
            type = CalcType.PV;
        }

        private void buttonCalculate_MouseClick(object sender, MouseEventArgs e)
        {
            double rate = double.Parse(textBoxRate.Text) /12 / 100;
            double nper = double.Parse(textBoxNper.Text);
            double pmt = double.Parse(textBoxPmt.Text);

            if(type == CalcType.FV)
            {
                double fv = (pmt * (Math.Pow(1 + rate, nper) - 1)) / rate;
                label4.Text = "FV = " + fv.ToString(".00"); 
            }
            else // type == PV
            {
                double pv = pmt * ((1 - Math.Pow(1 + rate, -nper)) / rate);
                label4.Text = "PV = " + pv.ToString(".00");
            }
            
        }

        private void radioButtonFV_CheckedChanged(object sender, EventArgs e)
        {
            type = CalcType.FV;
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}
