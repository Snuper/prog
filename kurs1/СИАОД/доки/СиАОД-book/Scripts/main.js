function changepre()
{
i=parseInt(parent.parent.head.tmp_form.tmp3.value);
document.write('<pre STYLE="font-size: ' + i + 'pt">');
}

function changep()
{
i=parseInt(parent.parent.head.tmp_form.tmp3.value);
document.write('<p STYLE="font-size: ' + i + 'pt">');
}

function changeh1()
{
i=parseInt(parent.parent.head.tmp_form.tmp3.value)+10;
document.write('<H1 STYLE="font-size: ' + i + 'pt">');
}

function changeh3()
{
i=parseInt(parent.parent.head.tmp_form.tmp3.value)+5;
document.write('<H3 STYLE="font-size: ' + i + 'pt">');
}
