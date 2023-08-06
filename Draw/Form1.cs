using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Draw
{
    public partial class Draw : Form
    {
        private bool toDraw = false;

        public Draw()
        {
            InitializeComponent();
        }

        private void Draw_MouseDown(object sender, MouseEventArgs e)
        {
            toDraw = true;
        }

        private void Draw_MouseUp(object sender, MouseEventArgs e)
        {
            toDraw = false;
        }

        private void Draw_MouseMove(object sender, MouseEventArgs e)
        {
            if(toDraw)
            {
                Graphics graphics = CreateGraphics();
                graphics.FillEllipse(new SolidBrush(Color.BlueViolet),
                    e.X, e.Y, 4, 4);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Invalidate();
        }
    }
}
