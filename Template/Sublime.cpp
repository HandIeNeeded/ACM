//ubuntu

{
    "cmd":["g++","${file}","-o","${file_path}/${file_base_name}"],
    "file_regex":"^(..[^:]*):([0-9]+)?([0-9]+)?:?(.*)$",
    "working_dir":"${file_path}",
    "selector":"source.c,source.cpp",
    "variants":
    [
    {
        "name":"Run",
        "cmd":["gnome-terminal","-x","bash","-c","g++ -std=c++11 '${file}' -o '${file_path}/${file_base_name}' && '${file_path}/${file_base_name}' ; read -n1 -p 'press any key to continue' "]
    }
    ]
}

//windows

{
    "file_regex": "^(..[^:]*):([0-9]+):?([0-9]+)?:? (.*)$",
    "working_dir": "${file_path}",
    "selector": "source.c, source.c++",
    "shell": true,
    "cmd": ["g++", "-std=c++11", "${file}", "-o", "${file_path}/${file_base_name}","-Wall", "&&","start"," ","${file_path}/cb_console_runner.exe","${file_base_name}"]
}

//其中 ${file_path}/cb_console_runner.exe 中的 ${file_path} 改成 codeblocks 文件夹的绝对路径