﻿// MyGraph.cs
using System;
using System.Drawing;
using System.Collections.Generic;


namespace Less_11_ex_02_graph
{
    [Serializable] // allow serialization: the objects can be stored 
    // and restored from file
    class MyGraph
    {
        private List<Vertex> vertices = new List<Vertex>();
        private List<List<int>> adjacencyList = 
            new List<List<int>>();
        private int selectedVertex = -1;
        private Color edgesColor = Color.Black;

        public void AddVertex(Vertex vertex)
        {
            vertices.Add(vertex);
            // add an empty adjacency list for new vertex
            adjacencyList.Add( new List<int>());
        }

        // returns index of vertex that
        // contains given point
        public int VertexAtPoint(Point point)
        {
            // find if ether vertex contains the given point
            for (int i = 0; i < vertices.Count; i++)
            {
                if (vertices[i].GetBounds().Contains(point))
                    return i;
            }
            return -1;
        }

        public void SelectVertex(int vertexIndex)
        {
            // deselect the previously selected vertex if necessary
            if (selectedVertex > -1)
            {
                vertices[selectedVertex].Selected = false;
            }
            // select new vertex
            selectedVertex = vertexIndex;
            vertices[selectedVertex].Selected = true;

        }

        public void DeselectVertex()
        {
            // deselect the previously selected vertex if necessary
            if (selectedVertex > -1)
            {
                vertices[selectedVertex].Selected = false;
            }
            // select new vertex
            selectedVertex = -1;
        }

        public void MoveSelectedVertex(Point point)
        {
            if (selectedVertex > -1) // there is a selected vertex
            {
                vertices[selectedVertex].SetLocation(point);
            }
        }

        public int SelectedVertex
        {
            get
            {
                return selectedVertex;
            }
        }

        public bool HasEdge(int uIndex, int vIndex)
        {
            if ((0 <= uIndex) && (uIndex < vertices.Count)
                && (0 <= vIndex) && (vIndex < vertices.Count))
            {
                foreach (int vertexIndex in adjacencyList[uIndex])
                    if(vertexIndex == vIndex)
                        return true;
            }
            return false;
                
        }

        public void AddEdge(int uIndex, int vIndex)
        {
            if((0 <= uIndex) && (uIndex < vertices.Count) 
                && (0 <= vIndex) && (vIndex < vertices.Count))
            {
                if(! HasEdge(uIndex, vIndex))
                {
                    adjacencyList[uIndex].Add(vIndex);
                    Console.WriteLine("\n Edge {0}--{1} added", uIndex, vIndex);
                }
            }
        }

        public void Draw(Graphics graphicsObject)
        {
            // draw edges
            Pen pen = new Pen(edgesColor);
            for(int uIndex = 0; uIndex < adjacencyList.Count; uIndex++)
            {
                foreach(int vIndex in adjacencyList[uIndex])
                {
                    graphicsObject.DrawLine(pen,
                        vertices[uIndex].XPos,
                        vertices[uIndex].YPos,
                        vertices[vIndex].XPos,
                        vertices[vIndex].YPos);
                }
                    
            }
            foreach(Vertex vertex in vertices )
            {
                vertex.Draw(graphicsObject);
            }
        }
                
        public int NumOfVertices
        {
            get
            {
                return vertices.Count;
            }
            // no set accessor
        }
    }
}

