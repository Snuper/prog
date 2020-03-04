import os
import sys
import argparse

def appendingToFile(filename, *args):
	file = open(filename, 'a')
	for a in args:
		file.write('\n' + a)
	file.close()

def newScalaSubProject(subprojectName, projectDir = os.getcwd()):
	mainDir = os.getcwd()
	os.chdir(projectDir)
	if not os.path.exists(subprojectName + "/src/main/scala"):
		os.makedirs(subprojectName + "/src/main/scala")
	if not os.path.exists(subprojectName + "/src/test/scala"):
		os.makedirs(subprojectName + "/src/test/scala")
	appendingToFile("build.sbt", "lazy val " + subprojectName + " = project")
	open(subprojectName + "/README.md", 'w').close()
	buildsbt = open(subprojectName + "/build.sbt", 'w')
	buildsbt.write("name := " + '"' + subprojectName + '"')
	buildsbt.close()
	os.chdir(mainDir)

if __name__ == "__main__":
	parser = argparse.ArgumentParser()
	parser.add_argument("-p" ,"--path", help="path to project")
	parser.add_argument("name", help="name subproject")
	args = parser.parse_args()
	if args.path:
		newScalaSubProject(args.name, args.path)
	else:
		newScalaSubProject(args.name)

