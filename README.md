# vcpkg-demo

1. 安装git

	https://www.git-scm.com/

2. 设置 vcpkg
	1. 克隆仓库

		git clone https://github.com/microsoft/vcpkg.git

	2. 运行启动脚本

		cd vcpkg && bootstrap-vcpkg.bat

	3. 与Visual Studio MSBuild集成
	
		.\vcpkg.exe integrate install

	4. 设置环境变量

		VCPKG_ROOT="C:\path\to\vcpkg"

		PATH=%VCPKG_ROOT%;%PATH%

3. 设置Visual Studio项目

	1. 打开命令行

		Visual Studio -> Tools -> Command Line -> Developer Command Prompt

	2. 创建vcpkg清单

		vcpkg new --application

	3. 添加依赖

		vcpkg add port fmt

	4. 启用清单模式

		Properties -> vcpkg -> Use Vcpkg Mainifest 设置为Yes
4. 生成并运行

	1. 生成项目 `Ctrl+Shift+B`

	2. 运行应用	`F5`

	

