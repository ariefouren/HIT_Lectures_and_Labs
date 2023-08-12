// MyGraph.cs
using System;
using System.Collections;
using System.Drawing;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Less_11_ex_02_graph
{
    class MyGraph
    {
        private ArrayList vertices = new ArrayList();
        private int selectedVertex = -1;

        public int SelectedVertex
        {
            get
            {
                return selectedVertex;
            }
        }

        public void AddVertex(Vertex vertex)
        {
            vertices.Add(vertex);
        }

        public void Draw(Graphics graphicsObject)
        {
            foreach(Vertex vertex in vertices )
            {
                vertex.Draw(graphicsObject);
            }
        }

        // returns index of vertex that
        // contains given point
        public void SelectVertex(Point point)
        {
            // find if ether vertex contains the given point
            for(int i = 0; i < vertices.Count; i++)
            {
                if (((Vertex)vertices[i]).GetBounds().Contains(point))
                    SelectVertex(i);
            }
        }
       
        void SelectVertex(int vertexIndex)
        {
            // deselect the previously selected vertex if necessary
            if (selectedVertex > -1)
            {
                ((Vertex)vertices[selectedVertex]).Selected = false;
            }
            // select new vertex
            selectedVertex = vertexIndex;
            ((Vertex)vertices[selectedVertex]).Selected = true;
            
        }

        public void DeselectVertex()
        {
            // deselect the previously selected vertex if necessary
            if (selectedVertex > -1)
            {
                ((Vertex)vertices[selectedVertex]).Selected = false;
            }
            // select new vertex
            selectedVertex = -1;
        }

        public void MoveSelectedVertex(Point point)
        {
            if(selectedVertex > -1) // there is a selected vertex
            {
                ((Vertex)vertices[selectedVertex]).SetLocation(point);
            }
        }

        public int NumOfVertices
        {
            get
            {
                return vertices.Count;
            }
            // no set accessors
        }
    }
}

