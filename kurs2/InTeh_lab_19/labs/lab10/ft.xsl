<?xml version = "1.0" ?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/">
<html>
	<head>
		<title>Lab 3.3.</title>
		<style type="text/css">
		button
{
	color: black;
  background: white;
  padding: 1.2rem 2rem;
  cursor: pointer;
  user-select: none;
  border: none;
  outline: none;
  transition: background 9999999s;
}

button:focus
{
	background: green;
  transition: background 0s;
}
 </style>
	</head>

	<body background-color = "white">
	<table border = "2" >
		<TR bgcolor = "#9acd32">
			<TH><button>Название</button></TH>
			<TH><button>Расстояние от солнца (а.е.)</button></TH>
			<TH><button>Период обращения (г.)</button></TH>
			<TH><button>Период вращение вокруг своей оси (ч.)</button></TH>
			<TH><button>Масса относительно Земли</button></TH>
			<TH><button>Диаметр (км.)</button></TH>
			<TH><button>Количество спутников</button></TH>
		</TR>
		<xsl:for-each select = "solar/planet[weight = 1.00]">
		<TR>
			<TD align = "center" ><xsl:value-of select = "@caption" /></TD>
			<TD align = "center" ><xsl:value-of select = "distance" /></TD>
			<TD align = "center" ><xsl:value-of select = "circulation_period" /></TD>
			<TD align = "center" ><xsl:value-of select = "revolution_period" /></TD>
			<TD align = "center" ><xsl:value-of select = "weight" /></TD>
			<TD align = "center" ><xsl:value-of select = "diametr" /></TD>
			<TD align = "center" ><xsl:value-of select = "satellite_number" /></TD>
		</TR>
		</xsl:for-each>
		<xsl:for-each select = "solar/planet[weight = 0.002]">
		<TR bgcolor = "grey">
			<TD align = "center" ><xsl:value-of select = "@caption" /></TD>
			<TD align = "center" ><xsl:value-of select = "distance" /></TD>
			<TD align = "center" ><xsl:value-of select = "circulation_period" /></TD>
			<TD align = "center" ><xsl:value-of select = "revolution_period" /></TD>
			<TD align = "center" ><xsl:value-of select = "weight" /></TD>
			<TD align = "center" ><xsl:value-of select = "diametr" /></TD>
			<TD align = "center" ><xsl:value-of select = "satellite_number" /></TD>
		</TR>
		</xsl:for-each>
		<xsl:for-each select = "solar/planet[weight = 0.11]">
		<TR>
			<TD align = "center" ><xsl:value-of select = "@caption" /></TD>
			<TD align = "center" ><xsl:value-of select = "distance" /></TD>
			<TD align = "center" ><xsl:value-of select = "circulation_period" /></TD>
			<TD align = "center" ><xsl:value-of select = "revolution_period" /></TD>
			<TD align = "center" ><xsl:value-of select = "weight" /></TD>
			<TD align = "center" ><xsl:value-of select = "diametr" /></TD>
			<TD align = "center" ><xsl:value-of select = "satellite_number" /></TD>
		</TR>
		</xsl:for-each>
		<xsl:for-each select = "solar/planet[weight = 17.2]">
		<TR bgcolor = "grey">
			<TD align = "center" ><xsl:value-of select = "@caption" /></TD>
			<TD align = "center" ><xsl:value-of select = "distance" /></TD>
			<TD align = "center" ><xsl:value-of select = "circulation_period" /></TD>
			<TD align = "center" ><xsl:value-of select = "revolution_period" /></TD>
			<TD align = "center" ><xsl:value-of select = "weight" /></TD>
			<TD align = "center" ><xsl:value-of select = "diametr" /></TD>
			<TD align = "center" ><xsl:value-of select = "satellite_number" /></TD>
		</TR>
		</xsl:for-each>
		<xsl:for-each select = "solar/planet[weight = 318.0]">
		<TR>
			<TD align = "center" ><xsl:value-of select = "@caption" /></TD>
			<TD align = "center" ><xsl:value-of select = "distance" /></TD>
			<TD align = "center" ><xsl:value-of select = "circulation_period" /></TD>
			<TD align = "center" ><xsl:value-of select = "revolution_period" /></TD>
			<TD align = "center" ><xsl:value-of select = "weight" /></TD>
			<TD align = "center" ><xsl:value-of select = "diametr" /></TD>
			<TD align = "center" ><xsl:value-of select = "satellite_number" /></TD>
		</TR>
		</xsl:for-each>
		<xsl:for-each select = "solar/planet[weight = 14.6]">
		<TR bgcolor = "grey">
			<TD align = "center" ><xsl:value-of select = "@caption" /></TD>
			<TD align = "center" ><xsl:value-of select = "distance" /></TD>
			<TD align = "center" ><xsl:value-of select = "circulation_period" /></TD>
			<TD align = "center" ><xsl:value-of select = "revolution_period" /></TD>
			<TD align = "center" ><xsl:value-of select = "weight" /></TD>
			<TD align = "center" ><xsl:value-of select = "diametr" /></TD>
			<TD align = "center" ><xsl:value-of select = "satellite_number" /></TD>
		</TR>
		</xsl:for-each>
		<xsl:for-each select = "solar/planet[weight = 95.1]">
		<TR>
			<TD align = "center" ><xsl:value-of select = "@caption" /></TD>
			<TD align = "center" ><xsl:value-of select = "distance" /></TD>
			<TD align = "center" ><xsl:value-of select = "circulation_period" /></TD>
			<TD align = "center" ><xsl:value-of select = "revolution_period" /></TD>
			<TD align = "center" ><xsl:value-of select = "weight" /></TD>
			<TD align = "center" ><xsl:value-of select = "diametr" /></TD>
			<TD align = "center" ><xsl:value-of select = "satellite_number" /></TD>
		</TR>
		</xsl:for-each>
	</table>
	</body>
</html>
</xsl:template>
</xsl:stylesheet>