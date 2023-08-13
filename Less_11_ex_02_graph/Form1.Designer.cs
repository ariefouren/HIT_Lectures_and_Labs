
namespace Less_11_ex_02_graph
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.groupBoxSelectType = new System.Windows.Forms.GroupBox();
            this.radioButtonEdges = new System.Windows.Forms.RadioButton();
            this.radioButtonVertices = new System.Windows.Forms.RadioButton();
            this.panelDraw = new System.Windows.Forms.Panel();
            this.labelOutput = new System.Windows.Forms.Label();
            this.groupBoxSelectType.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBoxSelectType
            // 
            this.groupBoxSelectType.Controls.Add(this.radioButtonEdges);
            this.groupBoxSelectType.Controls.Add(this.radioButtonVertices);
            this.groupBoxSelectType.Location = new System.Drawing.Point(592, 21);
            this.groupBoxSelectType.Name = "groupBoxSelectType";
            this.groupBoxSelectType.Size = new System.Drawing.Size(187, 112);
            this.groupBoxSelectType.TabIndex = 0;
            this.groupBoxSelectType.TabStop = false;
            this.groupBoxSelectType.Text = "Select Type";
            // 
            // radioButtonEdges
            // 
            this.radioButtonEdges.AutoSize = true;
            this.radioButtonEdges.Location = new System.Drawing.Point(25, 69);
            this.radioButtonEdges.Name = "radioButtonEdges";
            this.radioButtonEdges.Size = new System.Drawing.Size(80, 24);
            this.radioButtonEdges.TabIndex = 1;
            this.radioButtonEdges.TabStop = true;
            this.radioButtonEdges.Text = "Edges";
            this.radioButtonEdges.UseVisualStyleBackColor = true;
            // 
            // radioButtonVertices
            // 
            this.radioButtonVertices.AutoSize = true;
            this.radioButtonVertices.Location = new System.Drawing.Point(25, 30);
            this.radioButtonVertices.Name = "radioButtonVertices";
            this.radioButtonVertices.Size = new System.Drawing.Size(92, 24);
            this.radioButtonVertices.TabIndex = 0;
            this.radioButtonVertices.TabStop = true;
            this.radioButtonVertices.Text = "Vertices";
            this.radioButtonVertices.UseVisualStyleBackColor = true;
            // 
            // panelDraw
            // 
            this.panelDraw.BackColor = System.Drawing.SystemColors.ControlLightLight;
            this.panelDraw.Location = new System.Drawing.Point(22, 21);
            this.panelDraw.Name = "panelDraw";
            this.panelDraw.Size = new System.Drawing.Size(547, 403);
            this.panelDraw.TabIndex = 1;
            this.panelDraw.Click += new System.EventHandler(this.panel1_Click);
            this.panelDraw.Paint += new System.Windows.Forms.PaintEventHandler(this.panelDraw_Paint);
            this.panelDraw.MouseDown += new System.Windows.Forms.MouseEventHandler(this.panel1_MouseDown);
            this.panelDraw.MouseMove += new System.Windows.Forms.MouseEventHandler(this.panelDraw_MouseMove);
            this.panelDraw.MouseUp += new System.Windows.Forms.MouseEventHandler(this.panelDraw_MouseUp);
            // 
            // labelOutput
            // 
            this.labelOutput.AutoSize = true;
            this.labelOutput.Location = new System.Drawing.Point(598, 182);
            this.labelOutput.Name = "labelOutput";
            this.labelOutput.Size = new System.Drawing.Size(40, 20);
            this.labelOutput.TabIndex = 2;
            this.labelOutput.Text = "Test";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.AppWorkspace;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.labelOutput);
            this.Controls.Add(this.panelDraw);
            this.Controls.Add(this.groupBoxSelectType);
            this.Name = "Form1";
            this.Text = "Graph";
            this.groupBoxSelectType.ResumeLayout(false);
            this.groupBoxSelectType.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBoxSelectType;
        private System.Windows.Forms.RadioButton radioButtonEdges;
        private System.Windows.Forms.RadioButton radioButtonVertices;
        private System.Windows.Forms.Panel panelDraw;
        private System.Windows.Forms.Label labelOutput;
    }
}

