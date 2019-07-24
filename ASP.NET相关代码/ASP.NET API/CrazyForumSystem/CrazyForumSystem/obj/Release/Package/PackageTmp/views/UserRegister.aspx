<%@ Page Title="" Language="C#" MasterPageFile="~/Main.Master" AutoEventWireup="true" CodeBehind="UserRegister.aspx.cs" Inherits="CrazyForumSystem.views.UserRegister" %>
<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <div >
    <div style="color:white; font-weight:100;">
    <center>

        <p>
            &nbsp;</p>
        <p>
            <h1>疯狂论坛用户注册</h1></p>
        <br />
        姓名啊:<asp:TextBox ID="texLoginName" runat="server" ForeColor="#999999">不为空</asp:TextBox>
        <br />
        <br />
        用户名：<asp:TextBox ID="texLoginId" runat="server" ForeColor="#999999">不为空</asp:TextBox>
        <%--        <asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" ControlToValidate="texLoginId" ErrorMessage="注册用户名不符合规范"></asp:RequiredFieldValidator>--%>
        <br />
        <br />
        密码啊：<asp:TextBox ID="texLoginPwd" runat="server" TextMode="Password"></asp:TextBox>
        <%--<asp:RequiredFieldValidator ID="RequiredFieldValidator2" runat="server" ControlToValidate="texLoginPwd" ErrorMessage="注册密码不符合规范"></asp:RequiredFieldValidator>--%>
        <br />
        <br />
        验证码：<asp:TextBox ID="texTest" runat="server" ForeColor="#999999">不为空</asp:TextBox>
        <br />
        <br />
        <br />
        <asp:RadioButton ID="rbt0" runat="server" GroupName="Type" OnCheckedChanged="rbt0_CheckedChanged" Text="普通用户" />
        <asp:RadioButton ID="rbt1" runat="server" GroupName="Type" OnCheckedChanged="rbt1_CheckedChanged" Text="管理员" />
        <br />
        <br />
        <asp:Button ID="btnRegister" runat="server" Text="注册" OnClick="btnRegister_Click" />
        <br />
        <asp:Literal ID="ltaInfo" runat="server"></asp:Literal>
    </center>
</div>
</div>
</asp:Content>
