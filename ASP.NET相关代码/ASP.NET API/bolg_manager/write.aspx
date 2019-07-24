<%@ Page Language="C#" AutoEventWireup="true" CodeFile="write.aspx.cs" Inherits="Default2" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>编辑文章</title>
</head>
<body>
    <form id="form1" runat="server">
        
        <div class="wrapper" style="align-items:center; margin-left:250px" >
            <div class="title">
                <span>标题:</span>
                <input id="title_text" class="title_text" type="text" style="width:800px" autofocus="autofocus" checked="checked" placeholder="请输入文章标题"/>
                

                <!--<input id="fabu" type="button" value="发布" />-->
                <asp:Button ID="fabu" Text="发布" OnClick="fabu_Click" runat="server"/>
            </div>

                <span>分类:</span>
            <asp:DropDownList ID="article_list"  runat="server" Height="17px" Width="143px"></asp:DropDownList>
        </div>

        <div class="content" style="align-items:center;margin-left:250px;margin-top:10px">
            <asp:TextBox ID="article_content" runat="server" Width="900px" BackColor="#E9DAD1" Height="600px" style="margin-right: 11px"></asp:TextBox>
        </div>
    </form>
</body>
</html>
