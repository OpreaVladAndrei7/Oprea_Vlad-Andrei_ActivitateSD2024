namespace Form_ec2
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
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.cx2 = new System.Windows.Forms.TextBox();
            this.tl = new System.Windows.Forms.TextBox();
            this.cx = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.r1 = new System.Windows.Forms.TextBox();
            this.r2 = new System.Windows.Forms.TextBox();
            this.button2 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(218, 80);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(150, 25);
            this.label1.TabIndex = 0;
            this.label1.Text = "Coeficient X^2";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(218, 161);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(130, 25);
            this.label2.TabIndex = 1;
            this.label2.Text = "Coeficient X";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(218, 255);
            this.label3.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(133, 25);
            this.label3.TabIndex = 2;
            this.label3.Text = "Termen liber";
            // 
            // cx2
            // 
            this.cx2.Location = new System.Drawing.Point(430, 70);
            this.cx2.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.cx2.Name = "cx2";
            this.cx2.Size = new System.Drawing.Size(91, 30);
            this.cx2.TabIndex = 3;
            // 
            // tl
            // 
            this.tl.Location = new System.Drawing.Point(430, 245);
            this.tl.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.tl.Name = "tl";
            this.tl.Size = new System.Drawing.Size(91, 30);
            this.tl.TabIndex = 4;
            // 
            // cx
            // 
            this.cx.Location = new System.Drawing.Point(430, 161);
            this.cx.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.cx.Name = "cx";
            this.cx.Size = new System.Drawing.Size(91, 30);
            this.cx.TabIndex = 5;
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(4)))), ((int)(((byte)(121)))), ((int)(((byte)(200)))));
            this.button1.ForeColor = System.Drawing.Color.White;
            this.button1.Location = new System.Drawing.Point(52, 308);
            this.button1.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(612, 91);
            this.button1.TabIndex = 6;
            this.button1.Text = "Calcul Radacini";
            this.button1.UseVisualStyleBackColor = false;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(88, 410);
            this.label4.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(127, 25);
            this.label4.TabIndex = 7;
            this.label4.Text = "Radacina 1:";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(425, 410);
            this.label5.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(127, 25);
            this.label5.TabIndex = 8;
            this.label5.Text = "Radacina 2:";
            // 
            // r1
            // 
            this.r1.Location = new System.Drawing.Point(223, 407);
            this.r1.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.r1.Name = "r1";
            this.r1.ReadOnly = true;
            this.r1.Size = new System.Drawing.Size(91, 30);
            this.r1.TabIndex = 9;
            this.r1.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // r2
            // 
            this.r2.Location = new System.Drawing.Point(560, 405);
            this.r2.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.r2.Name = "r2";
            this.r2.ReadOnly = true;
            this.r2.Size = new System.Drawing.Size(91, 30);
            this.r2.TabIndex = 10;
            this.r2.TextChanged += new System.EventHandler(this.textBox2_TextChanged);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(599, 17);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(148, 36);
            this.button2.TabIndex = 11;
            this.button2.Text = "Inchide";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(13F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(761, 467);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.r2);
            this.Controls.Add(this.r1);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.cx);
            this.Controls.Add(this.tl);
            this.Controls.Add(this.cx2);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Form1";
            this.Text = "Rezolvare ec gr 2";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox cx2;
        private System.Windows.Forms.TextBox tl;
        private System.Windows.Forms.TextBox cx;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox r1;
        private System.Windows.Forms.TextBox r2;
        private System.Windows.Forms.Button button2;
    }
}

