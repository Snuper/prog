using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Text.RegularExpressions;
using System.Collections;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void openFileDialog1_FileOk(object sender, CancelEventArgs e)
        {

        }

        private void toolStripMenuItem1_Click(object sender, EventArgs e)
        {

        }

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog dlg = new OpenFileDialog();

            if (dlg.ShowDialog() == DialogResult.OK)
            {
                StreamReader reader = new StreamReader(dlg.FileName, Encoding.Default);
                txtFileContents.Text = reader.ReadToEnd();
                reader.Close();
            }

            dlg.Dispose();
        }

        private void hotButton(object sender, KeyEventArgs e )
        {
            if ((e.KeyCode == Keys.O) && e.Control)
            {
                OpenFileDialog dlg = new OpenFileDialog();

                if (dlg.ShowDialog() == DialogResult.OK)
                {
                    StreamReader reader = new StreamReader(dlg.FileName, Encoding.Default);
                    txtFileContents.Text = reader.ReadToEnd();
                    reader.Close();
                }

                dlg.Dispose();
            }
            if (e.KeyCode == Keys.S && e.Control)
            {
                SaveFileDialog dlg = new SaveFileDialog();

                if (dlg.ShowDialog() == DialogResult.OK)
                {
                    StreamWriter writer = new StreamWriter(dlg.FileName);
                    for (int i = 0; i < lstSection2.Items.Count; i++)
                    {
                        writer.WriteLine((string)lstSection2.Items[i]);
                    }
                    writer.Close();
                }

                dlg.Dispose();
            }
            if (e.KeyCode == Keys.X && e.Alt)
            {
                this.Close();
            }
        }

        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SaveFileDialog dlg = new SaveFileDialog();

            if (dlg.ShowDialog() == DialogResult.OK)
            {
                StreamWriter writer = new StreamWriter(dlg.FileName);
                for (int i = 0; i < lstSection2.Items.Count; i++)
                {
                    writer.WriteLine((string)lstSection2.Items[i]);
                }
                writer.Close();
            }

            dlg.Dispose();
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void btnReset_Click(object sender, EventArgs e)
        {
            lstSection1.Items.Clear();
            lstSection2.Items.Clear();
            lstSearchResults.Items.Clear();
            txtFileContents.Clear();
            chkSection1.Checked = true;
            chkSection2.Checked = false;
            rdoAll.Checked = true;
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            lstSection1.Items.Clear();
            lstSection2.Items.Clear();

            lstSection1.BeginUpdate();
            string[] strings = txtFileContents.Text.Split(new char[] { '\n', '\t', ' ' }, StringSplitOptions.RemoveEmptyEntries);
            foreach (string s in strings)
            {
                string str = s.Trim();
                if (str == String.Empty)
                    continue;
                if (rdoAll.Checked)
                {
                    lstSection1.Items.Add(str);
                }
                if (rdoDigits.Checked)
                {
                    if (Regex.IsMatch(str, @"\d"))
                        lstSection1.Items.Add(str);
                }
                if (rdoEmails.Checked)
                {
                    if (Regex.IsMatch(str, @"\w+@\w+\.\w+"))
                        lstSection1.Items.Add(str);
                }

            }
            lstSection1.EndUpdate();

        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Иванов Константин ИП-814");
        }

        private void DeleteSelectedItems(ListBox lstFrom)
        {
            lstFrom.Items.Remove(lstFrom.SelectedItem);  
        }


        private void MoveSelectedItems(ListBox lstFrom, ListBox lstTo)
        {
            lstTo.BeginUpdate();
            foreach (object item in lstFrom.SelectedItems)
            {
                lstTo.Items.Add(item);
            }
            lstTo.EndUpdate();

            DeleteSelectedItems(lstFrom);
        }

        private void MoveAllItems(ListBox lstFrom, ListBox lstTo)
        {
            lstTo.Items.AddRange(lstFrom.Items);
            lstFrom.Items.Clear();
        }


        private void btnDelete_Click(object sender, EventArgs e)
        {
            DeleteSelectedItems(lstSection1);
            DeleteSelectedItems(lstSection2);
        }

        private void btnMoveAllToSection1_Click(object sender, EventArgs e)
        {
            MoveAllItems(lstSection2, lstSection1);
        }

        private void btnMoveAllToSection2_Click(object sender, EventArgs e)
        {
            MoveAllItems(lstSection1, lstSection2);
        }

        private void btnMoveToSection1_Click(object sender, EventArgs e)
        {
            MoveSelectedItems(lstSection2, lstSection1);
        }

        private void btnMoveToSection2_Click(object sender, EventArgs e)
        {
            MoveSelectedItems(lstSection1, lstSection2);
        }
        
        private void SortListBox(ListBox list, int choose)
		{
            
			
			switch (choose)
			{
				case 0:
                    this.Cursor = Cursors.WaitCursor;

                     string[] stringsArray = new string[list.Items.Count];
                     list.Items.CopyTo(stringsArray, 0);
                     Array.Sort(stringsArray);
                     list.Items.Clear();
                     list.Items.AddRange(stringsArray);
                    
                     this.Cursor = Cursors.Default;
					break;
				case 1:
					this.Cursor = Cursors.WaitCursor;

                     string[] stringsArray1 = new string[list.Items.Count];
                     list.Items.CopyTo(stringsArray1, 0);
                     Array.Reverse(stringsArray1);
                     list.Items.Clear();
                     list.Items.AddRange(stringsArray1);
                    
                     this.Cursor = Cursors.Default;
					break;
				case 2:
					this.Cursor = Cursors.WaitCursor;

                     string[] stringsArray2 = new string[list.Items.Count];
                     list.Items.CopyTo(stringsArray2, 0);
                     Array.Sort(stringsArray2, (x, y) => x.Length.CompareTo(y.Length));
                     list.Items.Clear();
                     list.Items.AddRange(stringsArray2);
                    
                     this.Cursor = Cursors.Default;
					break;
				case 3:
					this.Cursor = Cursors.WaitCursor;

                     string[] stringsArray3 = new string[list.Items.Count];
                     list.Items.CopyTo(stringsArray3, 0);
                     Array.Sort(stringsArray3, (x, y) => x.Length.CompareTo(y.Length));
                     Array.Reverse(stringsArray3);
                     list.Items.Clear();
                     list.Items.AddRange(stringsArray3);
                    
                     this.Cursor = Cursors.Default;

					break; 
				default:
					MessageBox.Show("Выберите критерий сортировки!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
					return;
			}
            

        }

        private void btnAdd_Click_1(object sender, EventArgs e)
        {
            Form2 dlg = new Form2();
            dlg.Owner = this;
            dlg.ShowDialog();
        }

        private void btnClearSection1_Click_1(object sender, EventArgs e)
        {
            lstSection1.Items.Clear();
        }

        private void btnClearSection2_Click(object sender, EventArgs e)
        {
            lstSection2.Items.Clear();
        }

        private void btnFind_Click(object sender, EventArgs e)
        {
            lstSearchResults.Items.Clear();
            string textToFind = txtToFind.Text;

            if (chkSection1.Checked)
            {
                foreach (string s in lstSection1.Items)
                {
                    if (s.Contains(textToFind))
                        lstSearchResults.Items.Add(s);
                }
            }

            if (chkSection2.Checked)
            {
                foreach (string s in lstSection2.Items)
                {
                    if (s.Contains(textToFind))
                        lstSearchResults.Items.Add(s);
                }
            }
        }

        private void btnSortSection1_Click_1(object sender, EventArgs e)
        {
            SortListBox(lstSection1, SortOrderSection1.SelectedIndex);
        }

        private void btnSortSection2_Click(object sender, EventArgs e)
        {
            SortListBox(lstSection2, SortOrderSection2.SelectedIndex);
        }

        private void menuStrip1_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {

        }
    }
}
