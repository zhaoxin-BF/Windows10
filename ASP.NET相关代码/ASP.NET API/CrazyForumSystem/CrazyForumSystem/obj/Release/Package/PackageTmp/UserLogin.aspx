<%@ Page Title="" Language="C#" MasterPageFile="~/Main.Master" AutoEventWireup="true" CodeBehind="UserLogin.aspx.cs" Inherits="CrazyForumSystem.UserLogin" %>
<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <div style="color:white; font-weight:100;">
    <center>

        <p>
            &nbsp;</p>
        <p>
            <h1>疯狂论坛登录</h1></p>
        <br />
        用户名：<asp:TextBox ID="texLoginId" runat="server"></asp:TextBox>
        <br />
        <br />
        密码啊：<asp:TextBox ID="texLoginPwd" runat="server" TextMode="Password"></asp:TextBox>
        <br />
        <br />
        <br />
        <asp:RadioButton ID="rbt0" runat="server" GroupName="Type" OnCheckedChanged="rbt0_CheckedChanged" Text="普通用户" />
        <asp:RadioButton ID="rbt1" runat="server" GroupName="Type" OnCheckedChanged="rbt1_CheckedChanged" Text="管理员" />
        <br />
        <br />
        <asp:Button ID="btnLogin" runat="server" Text="登录" OnClick="btnLogin_Click" />
    &nbsp;&nbsp;&nbsp;&nbsp;
        <asp:Button ID="btnRegister" runat="server" Text="注册" OnClick="btnRegister_Click" />
        <br />
        <asp:Literal ID="ltaInfo" runat="server"></asp:Literal>
    </center>
</div>
</asp:Content>
