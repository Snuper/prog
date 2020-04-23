namespace WindowsFormsApp1
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.button5 = new System.Windows.Forms.Button();
            this.button6 = new System.Windows.Forms.Button();
            this.button7 = new System.Windows.Forms.Button();
            this.кодPKDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.странаDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.столицаDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.континентDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.населениеDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.страныдля2лабыBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.lab2DataSet = new WindowsFormsApp1.lab2DataSet();
            this.страныдля2лабыTableAdapter = new WindowsFormsApp1.lab2DataSetTableAdapters.Страныдля2лабыTableAdapter();
            this.textBox1 = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.страныдля2лабыBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.lab2DataSet)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridView1
            // 
            this.dataGridView1.AutoGenerateColumns = false;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.кодPKDataGridViewTextBoxColumn,
            this.странаDataGridViewTextBoxColumn,
            this.столицаDataGridViewTextBoxColumn,
            this.континентDataGridViewTextBoxColumn,
            this.населениеDataGridViewTextBoxColumn});
            this.dataGridView1.DataSource = this.страныдля2лабыBindingSource;
            this.dataGridView1.Location = new System.Drawing.Point(12, 12);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.Size = new System.Drawing.Size(541, 426);
            this.dataGridView1.TabIndex = 0;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(559, 12);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 40);
            this.button1.TabIndex = 1;
            this.button1.Text = "Всё";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(559, 58);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 40);
            this.button2.TabIndex = 2;
            this.button2.Text = "Начинается с \"К\"";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(559, 104);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(75, 40);
            this.button3.TabIndex = 3;
            this.button3.Text = "Содержит \"К\"";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // button4
            // 
            this.button4.Location = new System.Drawing.Point(640, 58);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(75, 40);
            this.button4.TabIndex = 4;
            this.button4.Text = "Южная Америка";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // button5
            // 
            this.button5.Location = new System.Drawing.Point(640, 12);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(75, 40);
            this.button5.TabIndex = 5;
            this.button5.Text = "Северная Америка";
            this.button5.UseVisualStyleBackColor = true;
            this.button5.Click += new System.EventHandler(this.button5_Click);
            // 
            // button6
            // 
            this.button6.Location = new System.Drawing.Point(721, 12);
            this.button6.Name = "button6";
            this.button6.Size = new System.Drawing.Size(75, 40);
            this.button6.TabIndex = 6;
            this.button6.Text = "Сортировать";
            this.button6.UseVisualStyleBackColor = true;
            this.button6.Click += new System.EventHandler(this.button6_Click);
            // 
            // button7
            // 
            this.button7.Location = new System.Drawing.Point(569, 397);
            this.button7.Name = "button7";
            this.button7.Size = new System.Drawing.Size(219, 30);
            this.button7.TabIndex = 7;
            this.button7.Text = "About";
            this.button7.UseVisualStyleBackColor = true;
            this.button7.Click += new System.EventHandler(this.button7_Click);
            // 
            // кодPKDataGridViewTextBoxColumn
            // 
            this.кодPKDataGridViewTextBoxColumn.DataPropertyName = "Код(PK)";
            this.кодPKDataGridViewTextBoxColumn.HeaderText = "Код(PK)";
            this.кодPKDataGridViewTextBoxColumn.Name = "кодPKDataGridViewTextBoxColumn";
            // 
            // странаDataGridViewTextBoxColumn
            // 
            this.странаDataGridViewTextBoxColumn.DataPropertyName = "Страна";
            this.странаDataGridViewTextBoxColumn.HeaderText = "Страна";
            this.странаDataGridViewTextBoxColumn.Name = "странаDataGridViewTextBoxColumn";
            // 
            // столицаDataGridViewTextBoxColumn
            // 
            this.столицаDataGridViewTextBoxColumn.DataPropertyName = "Столица";
            this.столицаDataGridViewTextBoxColumn.HeaderText = "Столица";
            this.столицаDataGridViewTextBoxColumn.Name = "столицаDataGridViewTextBoxColumn";
            // 
            // континентDataGridViewTextBoxColumn
            // 
            this.континентDataGridViewTextBoxColumn.DataPropertyName = "Континент";
            this.континентDataGridViewTextBoxColumn.HeaderText = "Континент";
            this.континентDataGridViewTextBoxColumn.Name = "континентDataGridViewTextBoxColumn";
            // 
            // населениеDataGridViewTextBoxColumn
            // 
            this.населениеDataGridViewTextBoxColumn.DataPropertyName = "Население";
            this.населениеDataGridViewTextBoxColumn.HeaderText = "Население";
            this.населениеDataGridViewTextBoxColumn.Name = "населениеDataGridViewTextBoxColumn";
            // 
            // страныдля2лабыBindingSource
            // 
            this.страныдля2лабыBindingSource.DataMember = "Страныдля2лабы";
            this.страныдля2лабыBindingSource.DataSource = this.lab2DataSet;
            // 
            // lab2DataSet
            // 
            this.lab2DataSet.DataSetName = "lab2DataSet";
            this.lab2DataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // страныдля2лабыTableAdapter
            // 
            this.страныдля2лабыTableAdapter.ClearBeforeFill = true;
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(569, 371);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(219, 20);
            this.textBox1.TabIndex = 8;
            this.textBox1.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.button7);
            this.Controls.Add(this.button6);
            this.Controls.Add(this.button5);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.dataGridView1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.страныдля2лабыBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.lab2DataSet)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridView1;
        private lab2DataSet lab2DataSet;
        private System.Windows.Forms.BindingSource страныдля2лабыBindingSource;
        private lab2DataSetTableAdapters.Страныдля2лабыTableAdapter страныдля2лабыTableAdapter;
        private System.Windows.Forms.DataGridViewTextBoxColumn кодPKDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn странаDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn столицаDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn континентDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn населениеDataGridViewTextBoxColumn;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.Button button6;
        private System.Windows.Forms.Button button7;
        private System.Windows.Forms.TextBox textBox1;
    }
}

