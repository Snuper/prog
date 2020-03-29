namespace WindowsFormsApplication1
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
            this.panel1 = new System.Windows.Forms.Panel();
            this.btnClearSection2 = new System.Windows.Forms.Button();
            this.btnSortSection2 = new System.Windows.Forms.Button();
            this.lstSection2 = new System.Windows.Forms.ListBox();
            this.btnClearSection1 = new System.Windows.Forms.Button();
            this.btnClose = new System.Windows.Forms.Button();
            this.btnReset = new System.Windows.Forms.Button();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.rdoEmails = new System.Windows.Forms.RadioButton();
            this.rdoDigits = new System.Windows.Forms.RadioButton();
            this.rdoAll = new System.Windows.Forms.RadioButton();
            this.btnStart = new System.Windows.Forms.Button();
            this.btnSortSection1 = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.chkSection2 = new System.Windows.Forms.CheckBox();
            this.chkSection1 = new System.Windows.Forms.CheckBox();
            this.lstSearchResults = new System.Windows.Forms.ListBox();
            this.label3 = new System.Windows.Forms.Label();
            this.txtToFind = new System.Windows.Forms.TextBox();
            this.btnFind = new System.Windows.Forms.Button();
            this.lstSection1 = new System.Windows.Forms.ListBox();
            this.panel2 = new System.Windows.Forms.Panel();
            this.btnDelete = new System.Windows.Forms.Button();
            this.btnAdd = new System.Windows.Forms.Button();
            this.btnMoveAllToSection1 = new System.Windows.Forms.Button();
            this.btnMoveAllToSection2 = new System.Windows.Forms.Button();
            this.btnMoveToSection1 = new System.Windows.Forms.Button();
            this.btnMoveToSection2 = new System.Windows.Forms.Button();
            this.SortOrderSection2 = new System.Windows.Forms.ComboBox();
            this.SortOrderSection1 = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.txtFileContents = new System.Windows.Forms.TextBox();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.toolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.openToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.aboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.panel1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.panel2.SuspendLayout();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.panel1.Controls.Add(this.btnClearSection2);
            this.panel1.Controls.Add(this.btnSortSection2);
            this.panel1.Controls.Add(this.lstSection2);
            this.panel1.Controls.Add(this.btnClearSection1);
            this.panel1.Controls.Add(this.btnClose);
            this.panel1.Controls.Add(this.btnReset);
            this.panel1.Controls.Add(this.groupBox2);
            this.panel1.Controls.Add(this.btnSortSection1);
            this.panel1.Controls.Add(this.groupBox1);
            this.panel1.Controls.Add(this.lstSection1);
            this.panel1.Controls.Add(this.panel2);
            this.panel1.Controls.Add(this.SortOrderSection2);
            this.panel1.Controls.Add(this.SortOrderSection1);
            this.panel1.Controls.Add(this.label2);
            this.panel1.Controls.Add(this.label1);
            this.panel1.Location = new System.Drawing.Point(22, 28);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(493, 482);
            this.panel1.TabIndex = 1;
            // 
            // btnClearSection2
            // 
            this.btnClearSection2.Location = new System.Drawing.Point(386, 246);
            this.btnClearSection2.Name = "btnClearSection2";
            this.btnClearSection2.Size = new System.Drawing.Size(85, 23);
            this.btnClearSection2.TabIndex = 21;
            this.btnClearSection2.Text = "Отчистить";
            this.btnClearSection2.UseVisualStyleBackColor = true;
            this.btnClearSection2.Click += new System.EventHandler(this.btnClearSection2_Click);
            // 
            // btnSortSection2
            // 
            this.btnSortSection2.Location = new System.Drawing.Point(298, 247);
            this.btnSortSection2.Name = "btnSortSection2";
            this.btnSortSection2.Size = new System.Drawing.Size(85, 23);
            this.btnSortSection2.TabIndex = 20;
            this.btnSortSection2.Text = "Сортировать";
            this.btnSortSection2.UseVisualStyleBackColor = true;
            this.btnSortSection2.Click += new System.EventHandler(this.btnSortSection2_Click);
            // 
            // lstSection2
            // 
            this.lstSection2.FormattingEnabled = true;
            this.lstSection2.Location = new System.Drawing.Point(298, 54);
            this.lstSection2.Name = "lstSection2";
            this.lstSection2.Size = new System.Drawing.Size(173, 186);
            this.lstSection2.TabIndex = 19;
            // 
            // btnClearSection1
            // 
            this.btnClearSection1.Location = new System.Drawing.Point(113, 250);
            this.btnClearSection1.Name = "btnClearSection1";
            this.btnClearSection1.Size = new System.Drawing.Size(85, 23);
            this.btnClearSection1.TabIndex = 18;
            this.btnClearSection1.Text = "Отчистить";
            this.btnClearSection1.UseVisualStyleBackColor = true;
            this.btnClearSection1.Click += new System.EventHandler(this.btnClearSection1_Click_1);
            // 
            // btnClose
            // 
            this.btnClose.Location = new System.Drawing.Point(410, 437);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(60, 23);
            this.btnClose.TabIndex = 13;
            this.btnClose.Text = "Close";
            this.btnClose.UseVisualStyleBackColor = true;
            this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
            // 
            // btnReset
            // 
            this.btnReset.Location = new System.Drawing.Point(411, 408);
            this.btnReset.Name = "btnReset";
            this.btnReset.Size = new System.Drawing.Size(60, 23);
            this.btnReset.TabIndex = 12;
            this.btnReset.Text = "Сброс";
            this.btnReset.UseVisualStyleBackColor = true;
            this.btnReset.Click += new System.EventHandler(this.btnReset_Click);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.rdoEmails);
            this.groupBox2.Controls.Add(this.rdoDigits);
            this.groupBox2.Controls.Add(this.rdoAll);
            this.groupBox2.Controls.Add(this.btnStart);
            this.groupBox2.Location = new System.Drawing.Point(253, 276);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(218, 100);
            this.groupBox2.TabIndex = 8;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Выбор слов";
            // 
            // rdoEmails
            // 
            this.rdoEmails.AutoSize = true;
            this.rdoEmails.Location = new System.Drawing.Point(7, 73);
            this.rdoEmails.Name = "rdoEmails";
            this.rdoEmails.Size = new System.Drawing.Size(131, 17);
            this.rdoEmails.TabIndex = 17;
            this.rdoEmails.Text = "Содержащие \"e-mail\"";
            this.rdoEmails.UseVisualStyleBackColor = true;
            // 
            // rdoDigits
            // 
            this.rdoDigits.AutoSize = true;
            this.rdoDigits.Location = new System.Drawing.Point(7, 50);
            this.rdoDigits.Name = "rdoDigits";
            this.rdoDigits.Size = new System.Drawing.Size(128, 17);
            this.rdoDigits.TabIndex = 16;
            this.rdoDigits.Text = "Содержащие цифры";
            this.rdoDigits.UseVisualStyleBackColor = true;
            // 
            // rdoAll
            // 
            this.rdoAll.AutoSize = true;
            this.rdoAll.Checked = true;
            this.rdoAll.Location = new System.Drawing.Point(7, 27);
            this.rdoAll.Name = "rdoAll";
            this.rdoAll.Size = new System.Drawing.Size(44, 17);
            this.rdoAll.TabIndex = 15;
            this.rdoAll.TabStop = true;
            this.rdoAll.Text = "Все";
            this.rdoAll.UseVisualStyleBackColor = true;
            // 
            // btnStart
            // 
            this.btnStart.Location = new System.Drawing.Point(158, 57);
            this.btnStart.Name = "btnStart";
            this.btnStart.Size = new System.Drawing.Size(54, 37);
            this.btnStart.TabIndex = 14;
            this.btnStart.Text = "Начать";
            this.btnStart.UseVisualStyleBackColor = true;
            this.btnStart.Click += new System.EventHandler(this.btnStart_Click);
            // 
            // btnSortSection1
            // 
            this.btnSortSection1.Location = new System.Drawing.Point(22, 251);
            this.btnSortSection1.Name = "btnSortSection1";
            this.btnSortSection1.Size = new System.Drawing.Size(85, 23);
            this.btnSortSection1.TabIndex = 8;
            this.btnSortSection1.Text = "Сортировать";
            this.btnSortSection1.UseVisualStyleBackColor = true;
            this.btnSortSection1.Click += new System.EventHandler(this.btnSortSection1_Click_1);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.chkSection2);
            this.groupBox1.Controls.Add(this.chkSection1);
            this.groupBox1.Controls.Add(this.lstSearchResults);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.txtToFind);
            this.groupBox1.Controls.Add(this.btnFind);
            this.groupBox1.Location = new System.Drawing.Point(22, 277);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(150, 189);
            this.groupBox1.TabIndex = 7;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Поиск";
            this.groupBox1.Enter += new System.EventHandler(this.groupBox1_Enter);
            // 
            // chkSection2
            // 
            this.chkSection2.AutoSize = true;
            this.chkSection2.Location = new System.Drawing.Point(7, 164);
            this.chkSection2.Name = "chkSection2";
            this.chkSection2.Size = new System.Drawing.Size(72, 17);
            this.chkSection2.TabIndex = 24;
            this.chkSection2.Text = "Раздел 2";
            this.chkSection2.UseVisualStyleBackColor = true;
            // 
            // chkSection1
            // 
            this.chkSection1.AutoSize = true;
            this.chkSection1.Checked = true;
            this.chkSection1.CheckState = System.Windows.Forms.CheckState.Checked;
            this.chkSection1.Location = new System.Drawing.Point(7, 146);
            this.chkSection1.Name = "chkSection1";
            this.chkSection1.Size = new System.Drawing.Size(72, 17);
            this.chkSection1.TabIndex = 23;
            this.chkSection1.Text = "Раздел 1";
            this.chkSection1.UseVisualStyleBackColor = true;
            // 
            // lstSearchResults
            // 
            this.lstSearchResults.FormattingEnabled = true;
            this.lstSearchResults.Location = new System.Drawing.Point(6, 68);
            this.lstSearchResults.Name = "lstSearchResults";
            this.lstSearchResults.Size = new System.Drawing.Size(137, 69);
            this.lstSearchResults.TabIndex = 22;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(6, 26);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(129, 13);
            this.label3.TabIndex = 14;
            this.label3.Text = "Введите искомое слово";
            this.label3.Click += new System.EventHandler(this.label3_Click);
            // 
            // txtToFind
            // 
            this.txtToFind.Location = new System.Drawing.Point(6, 42);
            this.txtToFind.Name = "txtToFind";
            this.txtToFind.Size = new System.Drawing.Size(137, 20);
            this.txtToFind.TabIndex = 16;
            // 
            // btnFind
            // 
            this.btnFind.Location = new System.Drawing.Point(89, 146);
            this.btnFind.Name = "btnFind";
            this.btnFind.Size = new System.Drawing.Size(54, 37);
            this.btnFind.TabIndex = 15;
            this.btnFind.Text = "Поиск";
            this.btnFind.UseVisualStyleBackColor = true;
            this.btnFind.Click += new System.EventHandler(this.btnFind_Click);
            // 
            // lstSection1
            // 
            this.lstSection1.FormattingEnabled = true;
            this.lstSection1.Location = new System.Drawing.Point(22, 58);
            this.lstSection1.Name = "lstSection1";
            this.lstSection1.SelectionMode = System.Windows.Forms.SelectionMode.MultiExtended;
            this.lstSection1.Size = new System.Drawing.Size(173, 186);
            this.lstSection1.TabIndex = 5;
            // 
            // panel2
            // 
            this.panel2.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.panel2.Controls.Add(this.btnDelete);
            this.panel2.Controls.Add(this.btnAdd);
            this.panel2.Controls.Add(this.btnMoveAllToSection1);
            this.panel2.Controls.Add(this.btnMoveAllToSection2);
            this.panel2.Controls.Add(this.btnMoveToSection1);
            this.panel2.Controls.Add(this.btnMoveToSection2);
            this.panel2.Location = new System.Drawing.Point(201, 57);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(91, 186);
            this.panel2.TabIndex = 4;
            // 
            // btnDelete
            // 
            this.btnDelete.Location = new System.Drawing.Point(3, 156);
            this.btnDelete.Name = "btnDelete";
            this.btnDelete.Size = new System.Drawing.Size(81, 23);
            this.btnDelete.TabIndex = 17;
            this.btnDelete.Text = "Удалить";
            this.btnDelete.UseVisualStyleBackColor = true;
            this.btnDelete.Click += new System.EventHandler(this.btnDelete_Click);
            // 
            // btnAdd
            // 
            this.btnAdd.Location = new System.Drawing.Point(3, 127);
            this.btnAdd.Name = "btnAdd";
            this.btnAdd.Size = new System.Drawing.Size(81, 23);
            this.btnAdd.TabIndex = 16;
            this.btnAdd.Text = "Добавить";
            this.btnAdd.UseVisualStyleBackColor = true;
            this.btnAdd.Click += new System.EventHandler(this.btnAdd_Click_1);
            // 
            // btnMoveAllToSection1
            // 
            this.btnMoveAllToSection1.Location = new System.Drawing.Point(3, 80);
            this.btnMoveAllToSection1.Name = "btnMoveAllToSection1";
            this.btnMoveAllToSection1.Size = new System.Drawing.Size(81, 23);
            this.btnMoveAllToSection1.TabIndex = 15;
            this.btnMoveAllToSection1.Text = "<<";
            this.btnMoveAllToSection1.UseVisualStyleBackColor = true;
            this.btnMoveAllToSection1.Click += new System.EventHandler(this.btnMoveAllToSection1_Click);
            // 
            // btnMoveAllToSection2
            // 
            this.btnMoveAllToSection2.Location = new System.Drawing.Point(3, 54);
            this.btnMoveAllToSection2.Name = "btnMoveAllToSection2";
            this.btnMoveAllToSection2.Size = new System.Drawing.Size(81, 23);
            this.btnMoveAllToSection2.TabIndex = 14;
            this.btnMoveAllToSection2.Text = ">>";
            this.btnMoveAllToSection2.UseVisualStyleBackColor = true;
            this.btnMoveAllToSection2.Click += new System.EventHandler(this.btnMoveAllToSection2_Click);
            // 
            // btnMoveToSection1
            // 
            this.btnMoveToSection1.Location = new System.Drawing.Point(3, 28);
            this.btnMoveToSection1.Name = "btnMoveToSection1";
            this.btnMoveToSection1.Size = new System.Drawing.Size(81, 23);
            this.btnMoveToSection1.TabIndex = 13;
            this.btnMoveToSection1.Text = "<";
            this.btnMoveToSection1.UseVisualStyleBackColor = true;
            this.btnMoveToSection1.Click += new System.EventHandler(this.btnMoveToSection1_Click);
            // 
            // btnMoveToSection2
            // 
            this.btnMoveToSection2.Location = new System.Drawing.Point(3, 3);
            this.btnMoveToSection2.Name = "btnMoveToSection2";
            this.btnMoveToSection2.Size = new System.Drawing.Size(81, 23);
            this.btnMoveToSection2.TabIndex = 12;
            this.btnMoveToSection2.Text = ">";
            this.btnMoveToSection2.UseVisualStyleBackColor = true;
            this.btnMoveToSection2.Click += new System.EventHandler(this.btnMoveToSection2_Click);
            // 
            // SortOrderSection2
            // 
            this.SortOrderSection2.FormattingEnabled = true;
            this.SortOrderSection2.Items.AddRange(new object[] {
            "Алфавиту (по возрастанию)",
            "Алфавиту (по убыванию)",
            "Длине слова (по возрастанию)",
            "Длине слова (по убыванию) "});
            this.SortOrderSection2.Location = new System.Drawing.Point(298, 27);
            this.SortOrderSection2.Name = "SortOrderSection2";
            this.SortOrderSection2.Size = new System.Drawing.Size(173, 21);
            this.SortOrderSection2.TabIndex = 3;
            this.SortOrderSection2.Text = "Сортировка по ...";
            // 
            // SortOrderSection1
            // 
            this.SortOrderSection1.DisplayMember = "Alphabetically";
            this.SortOrderSection1.FormattingEnabled = true;
            this.SortOrderSection1.Items.AddRange(new object[] {
            "Алфавиту (по возрастанию)",
            "Алфавиту (по убыванию)",
            "Длине слова (по возрастанию)",
            "Длине слова (по убыванию) "});
            this.SortOrderSection1.Location = new System.Drawing.Point(22, 30);
            this.SortOrderSection1.Name = "SortOrderSection1";
            this.SortOrderSection1.Size = new System.Drawing.Size(173, 21);
            this.SortOrderSection1.TabIndex = 2;
            this.SortOrderSection1.Text = "Сортировка по ...";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(295, 11);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(53, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "Раздел 2";
            this.label2.Click += new System.EventHandler(this.label2_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(19, 13);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(53, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Раздел 1";
            // 
            // txtFileContents
            // 
            this.txtFileContents.Location = new System.Drawing.Point(521, 28);
            this.txtFileContents.Multiline = true;
            this.txtFileContents.Name = "txtFileContents";
            this.txtFileContents.Size = new System.Drawing.Size(226, 482);
            this.txtFileContents.TabIndex = 2;
            // 
            // menuStrip1
            // 
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripMenuItem1,
            this.aboutToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(759, 24);
            this.menuStrip1.TabIndex = 3;
            this.menuStrip1.Text = "menuStrip1";
            this.menuStrip1.ItemClicked += new System.Windows.Forms.ToolStripItemClickedEventHandler(this.menuStrip1_ItemClicked);
            // 
            // toolStripMenuItem1
            // 
            this.toolStripMenuItem1.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.openToolStripMenuItem,
            this.saveToolStripMenuItem,
            this.exitToolStripMenuItem});
            this.toolStripMenuItem1.Name = "toolStripMenuItem1";
            this.toolStripMenuItem1.Size = new System.Drawing.Size(37, 20);
            this.toolStripMenuItem1.Text = "File";
            this.toolStripMenuItem1.Click += new System.EventHandler(this.toolStripMenuItem1_Click);
            // 
            // openToolStripMenuItem
            // 
            this.openToolStripMenuItem.Name = "openToolStripMenuItem";
            this.openToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.openToolStripMenuItem.Text = "Open        Ctrl+O";
            this.openToolStripMenuItem.Click += new System.EventHandler(this.openToolStripMenuItem_Click);
            // 
            // saveToolStripMenuItem
            // 
            this.saveToolStripMenuItem.Name = "saveToolStripMenuItem";
            this.saveToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.saveToolStripMenuItem.Text = "Save          Ctrl+S";
            this.saveToolStripMenuItem.Click += new System.EventHandler(this.saveToolStripMenuItem_Click);
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            this.exitToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.exitToolStripMenuItem.Text = "Exit             Alt+X";
            this.exitToolStripMenuItem.Click += new System.EventHandler(this.exitToolStripMenuItem_Click);
            // 
            // aboutToolStripMenuItem
            // 
            this.aboutToolStripMenuItem.Name = "aboutToolStripMenuItem";
            this.aboutToolStripMenuItem.Size = new System.Drawing.Size(24, 20);
            this.aboutToolStripMenuItem.Text = "?";
            this.aboutToolStripMenuItem.Click += new System.EventHandler(this.aboutToolStripMenuItem_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(759, 527);
            this.Controls.Add(this.txtFileContents);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.panel2.ResumeLayout(false);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button btnClose;
        private System.Windows.Forms.Button btnReset;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Button btnStart;
        private System.Windows.Forms.Button btnSortSection1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TextBox txtToFind;
        private System.Windows.Forms.Button btnFind;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Button btnDelete;
        private System.Windows.Forms.Button btnAdd;
        private System.Windows.Forms.Button btnMoveAllToSection1;
        private System.Windows.Forms.Button btnMoveAllToSection2;
        private System.Windows.Forms.Button btnMoveToSection1;
        private System.Windows.Forms.Button btnMoveToSection2;
        private System.Windows.Forms.ComboBox SortOrderSection2;
        private System.Windows.Forms.ComboBox SortOrderSection1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox txtFileContents;
        private System.Windows.Forms.Button btnClearSection2;
        private System.Windows.Forms.Button btnSortSection2;
        private System.Windows.Forms.Button btnClearSection1;
        private System.Windows.Forms.RadioButton rdoEmails;
        private System.Windows.Forms.RadioButton rdoDigits;
        private System.Windows.Forms.RadioButton rdoAll;
        private System.Windows.Forms.CheckBox chkSection2;
        private System.Windows.Forms.CheckBox chkSection1;
        private System.Windows.Forms.ListBox lstSearchResults;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem openToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem aboutToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem2;
        public System.Windows.Forms.ListBox lstSection1;
        public System.Windows.Forms.ListBox lstSection2;
    }
}

