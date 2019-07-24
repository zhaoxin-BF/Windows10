<%@ Page Language="C#" AutoEventWireup="true" CodeFile="login.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style type="text/css">
        .auto-style1 {
            text-align: center;
        }
        .auto-style2 {
            width: 100%;
            float: left;
        }
        #Text1 {
            text-align: left;
        }
        #Password1 {}
        .auto-style3 {
            height: 27px;
        }
        .auto-style4 {
            height: 27px;
            width: 100px;
        }
        .auto-style5 {
            width: 100px;
        }
        .auto-style6 {
            width: 102px;
        }
    </style>
    <script>    
       username = document.getElementById("username");
       pass = document.getElementById("password");
       
    </script>
</head>
<body style="text-align:center;margin:0;padding:0; background-color:aliceblue; background-image:url(images/sea.png);" runat="server">
    <form id="form1" runat="server">
    <div style="align-items:center; text-align:center;width:100%; margin:0 auto">
    
        <div class="auto-style1" style="margin:60px">
            <h1>BLOG MANAGER</h1>
        </div>

        <h2 class="" style="margin:30px ;text-align:center" >登陆</h2>
      

        <div style="margin-left:580px;align-self:center;float:none; clear:both; ">

        <table align="center" class="auto-style2" style="width:50%; text-align:center; margin:30px auto; align-self:center;" >
                <tr>
                    <td style="text-align: right" class="auto-style4">用户名</td>
                    <td class="auto-style3" colspan="2">
                       <!-- <input id="username" type="text" style="float:left" class="username" required="required" placeholder="请输入用户名" />-->
                        <asp:TextBox ID="username" runat="server" style="float:left" required="required" placeholder="请输入用户名" autofocus="autofocus"></asp:TextBox>
                    </td>
                </tr>
                <tr>
                    <td style="text-align: right" class="auto-style5">密码</td>
                    <td colspan="2">
                       <!-- <input id="password" type="password" style="float:left"  required="required" class="password" autofocus="autofocus" placeholder="请输入密码" />-->
                        <asp:TextBox ID="password" runat="server" style="float:left"  required="required"   placeholder="请输入密码" TextMode="Password"></asp:TextBox>
        
        <asp:Label ID="error" runat="server" Text=""></asp:Label>
        
                    </td>
                </tr>
                <tr>
                    <td style="text-align: right" class="auto-style5">&nbsp;</td>
                    <td colspan="2">
                        &nbsp;</td>
                </tr>
                <tr>
                    <td class="auto-style5">&nbsp;</td>
                    <td class="auto-style6">
                        <!--<input id="login_reset" type="reset" value="重置" style="float:left"/>-->
                        <asp:Button ID="login_reset" Text="重置" OnClick="login_reset_Click" style="float:left" runat="server"/>&nbsp&nbsp</td>
                    <td>
                        <!--<input id="login" type="submit" value="登陆" style="float:left; margin-left: 0px;"/>-->
                    <asp:Button ID="login" Text="登陆" OnClick="login_Click" style="float:left; margin-left: 0px;" runat="server"/></td>
                </tr>
            </table>
        </div>
    </div>
        
    </form>
    
</body>
</html>
