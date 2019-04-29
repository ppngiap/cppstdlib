import sys
import os
import glob

def get_main_files(subdir):
    files = [s.replace(subdir + "/", "") for s in glob.glob(subdir + "/*.cpp")]
    print files
    return files

def mkdir_if_need_to(dir):
    if not os.path.isdir(dir):
        os.mkdir(dir)

def gen_proj_if_need_to(pro, subdir, filename):
    if not os.path.isfile(pro):
        content = open("tools/template.pro").read();
        content = content.replace("template_dir", subdir);
        content = content.replace("template.cpp", filename);
        f = open(pro, "w")
        f.write(content)
        print "gen project " + pro


def gen_proj(subdir, filename):
    dirpath= os.path.join("project", subdir, filename.replace(".cpp", ""))
    mkdir_if_need_to(dirpath)
    gen_proj_if_need_to(os.path.join(dirpath, filename.replace(".cpp", ".pro")), subdir, filename)

def gen_subdir_proj(subdir, files):
    dirs = [s.replace(".cpp", "") for s in files]
    mkdir_if_need_to("project")
    mkdir_if_need_to(os.path.join("project", subdir));
    f = open(os.path.join("project", subdir, subdir + ".pro"), "w")
    f.write("TEMPLATE = subdirs\n\n")
    for d in dirs:
        f.write("SUBDIRS += " + d + "\n")

def main():
    subdir = sys.argv[1]
    files = get_main_files(subdir)
    gen_subdir_proj(subdir, files)
    for f in files:
        gen_proj(subdir, f)

if __name__ == "__main__":
    main()