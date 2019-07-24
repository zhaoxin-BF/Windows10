<%@ Page Title="" Language="C#" MasterPageFile="~/Main.Master" AutoEventWireup="true" CodeBehind="UserLogin.aspx.cs" Inherits="CrazyForumSystem.UserLogin" %>
<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <div style="color:white; font-weight:100;">
    <center>

        <p>&nbsp;</p>
        <p><h1>疯狂论坛登录</h1></p>
        <table style="border:dashed;auto;">
            <thead>
					<tr >
						<th style="width:100px;float:right;"></th>
						<th style="width:200px;"></th>
					</tr>
			</thead>
            <tbody  >
					<tr>
						<td style="float:right">用户名</td>
						<td><asp:TextBox ID="texLoginId" runat="server"></asp:TextBox></td>
					</tr>
                	<tr>
						<td>&nbsp;</td>
						<td></td>
					</tr>
					<tr>
						<td style="float:right">密码啊</td>
						<td><asp:TextBox ID="texLoginPwd" runat="server" TextMode="Password"></asp:TextBox></td>
					</tr>
                    <tr>
						<td>&nbsp;</td>
						<td></td>
					</tr>
                	<tr>
						<td style="float:right"><%--选择身份--%></td>
						<td>
                            <asp:RadioButton ID="rbt0" runat="server" GroupName="Type" OnCheckedChanged="rbt0_CheckedChanged" Text="普通用户" />
                            <asp:RadioButton ID="rbt1" runat="server" GroupName="Type" OnCheckedChanged="rbt1_CheckedChanged" Text="管理员" />
						</td>
                        
					</tr>
                    <tr>
						<td>&nbsp;</td>
                        <td><asp:Literal ID="ltaInfo" runat="server"></asp:Literal></td>
					</tr>
					<tr>
						<td></td>
						<td>&nbsp;&nbsp;
                            <asp:Button ID="btnLogin" runat="server" Text="登录" OnClick="btnLogin_Click" />
                            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                            <asp:Button ID="btnRegister" runat="server" Text="注册" OnClick="btnRegister_Click" />
						</td>
					</tr>
				</tbody>    
        </table>
    </center>
</div>
</asp:Content>
