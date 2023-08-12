// Form1.cs
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Less_11_ex_02_graph
{
    public partial class Form1 : Form
    {
        private MyGraph graph = new MyGraph();

        public Form1()
        {
            InitializeComponent();
        }

        private void panel1_Click(object sender, EventArgs e)
        {

        }

        private void panel1_MouseDown(object sender, 
            MouseEventArgs e)
        {
            // check if there is a vertex located at 
            // the mouse click point
            Point point = new Point(e.X, e.Y);
            graph.SelectVertex(point);
            if(graph.SelectedVertex == -1)
            {// no vertex at the give point -
             // create a new vertex
                string label = graph.NumOfVertices.ToString();
                int radius = 15;
                Vertex newVertex = new Vertex(e.X, e.Y, radius, label);
                graph.AddVertex(newVertex);
            }
            panelDraw.Invalidate();
        }

        private void panelDraw_Paint(object sender, 
            PaintEventArgs e)
        {
            Graphics graphicsObject = e.Graphics;
            graphicsObject.SmoothingMode = 
                System.Drawing.Drawing2D.SmoothingMode.HighQuality;
            graph.Draw(graphicsObject);
        }

        private void panelDraw_MouseMove(object sender, MouseEventArgs e)
        {
            Point point = new Point(e.X, e.Y);
            graph.MoveSelectedVertex(point);
            if (graph.SelectedVertex > -1)
            {
                Rectangle invalidateRactangle =
                  new Rectangle(point.X - 50, point.Y - 50, 100, 100);
                panelDraw.Invalidate(invalidateRactangle);
            }

        }

        private void panelDraw_MouseUp(object sender, MouseEventArgs e)
        {
            graph.DeselectVertex();
            panelDraw.Invalidate();

        }
    }

    // TODO:
    // 1. Convert ArrayList to List<T>
    // 2. Implement serialization
    // 3. Implement edges
    // 4. Implement vertex delete (?)
    // 5. Implement vertex inheritance

}
