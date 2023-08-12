using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Class_11_ex_03_paint
{
    public partial class Form1 : Form
    {
        private bool toDraw = false;

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Invalidate();
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            toDraw = true;
        }

        private void Form1_MouseUp(object sender, MouseEventArgs e)
        {
            toDraw = false;
        }

        private void Form1_MouseMove(object sender, 
            MouseEventArgs e)
        {
            if (toDraw)
            {
                Graphics graphics = CreateGraphics();
                Brush brush = new SolidBrush(Color.DarkBlue);
                graphics.FillEllipse(brush, e.X, e.Y, 4, 4);
            }
        }
    }
}
