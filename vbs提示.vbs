Set objShell = WScript.CreateObject("WScript.Shell")
strTitle = "我帮你看河北网络学院V2.0"
strPrompt="作者：不停止_nocease"& vbCrLf & vbCrLf & "本项目使用的开发语言为C#，基于微软.Net Framework 4.7.2开发" & vbCrLf & vbCrLf & "推荐使用Win8/10/11系统" & vbCrLf & vbCrLf & "使用Win7或更低版本系统可能需要安装微软.Net Framework 4.7.2补丁" & vbCrLf & vbCrLf & "本项目仅供学习交流，下载后请在24小时内删除，不得用于非法用途"
intResult = objShell.Popup(strPrompt,0, strTitle, vbSystemModal + vbOKCancel)

If intResult = vbOK Then
    strPath = WScript.ScriptFullName
    strFolder = Left(strPath, InStrRev(strPath, "\"))
    strCommand = strFolder & "c#的Ajax.txt"
    objShell.Run strCommand, 1, True
End If