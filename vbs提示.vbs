Set objShell = WScript.CreateObject("WScript.Shell")
strTitle = "�Ұ��㿴�ӱ�����ѧԺV2.0"
strPrompt="���ߣ���ֹͣ_nocease"& vbCrLf & vbCrLf & "����Ŀʹ�õĿ�������ΪC#������΢��.Net Framework 4.7.2����" & vbCrLf & vbCrLf & "�Ƽ�ʹ��Win8/10/11ϵͳ" & vbCrLf & vbCrLf & "ʹ��Win7����Ͱ汾ϵͳ������Ҫ��װ΢��.Net Framework 4.7.2����" & vbCrLf & vbCrLf & "����Ŀ����ѧϰ���������غ�����24Сʱ��ɾ�����������ڷǷ���;"
intResult = objShell.Popup(strPrompt,0, strTitle, vbSystemModal + vbOKCancel)

If intResult = vbOK Then
    strPath = WScript.ScriptFullName
    strFolder = Left(strPath, InStrRev(strPath, "\"))
    strCommand = strFolder & "c#��Ajax.txt"
    objShell.Run strCommand, 1, True
End If