<%@ Page Title="" Language="C#" MasterPageFile="~/Main.Master" AutoEventWireup="true" CodeBehind="UserRegister.aspx.cs" Inherits="CrazyForumSystem.views.UserRegister" %>
<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <div >
    <div style="color:white; font-weight:100;">
    <center>

        <p>&nbsp;</p>
        <p><h1>疯狂论坛用户注册</h1></p>
        <table style="border:dashed;auto;">
            <thead>
					<tr >
						<th style="width:100px;float:right;"></th>
						<th style="width:150px;"></th>
						<th style="width:150px;"></th>
					</tr>
			</thead>
            <tbody  >
					<tr>
						<td style="float:right">姓名：</td>
						<td><asp:TextBox ID="texLoginName" runat="server"></asp:TextBox></td>
						<td>
                            <asp:RequiredFieldValidator ID="RFLoginName" runat="server" ControlToValidate="texLoginName" Display="Dynamic" ErrorMessage="姓名不能为空"></asp:RequiredFieldValidator>
                        </td>
					</tr>
                	<tr>
						<td>&nbsp;</td>
						<td></td>
						<td></td>
					</tr>
                	<tr>
						<td style="float:right">用户名：</td>
						<td><asp:TextBox ID="texLoginId" runat="server"></asp:TextBox></td>
						<td>
                            <asp:RequiredFieldValidator ID="RFLoginId" runat="server" ControlToValidate="texLoginId" Display="Dynamic" ErrorMessage="用户名不能为空"></asp:RequiredFieldValidator>
                        </td>
					</tr>
                	<tr>
						<td>&nbsp;</td>
						<td></td>
						<td></td>
					</tr>
					<tr>
						<td style="float:right">密码：</td>
						<td><asp:TextBox ID="texLoginPwd" runat="server" TextMode="Password"></asp:TextBox></td>
						<td>
                            <asp:RequiredFieldValidator ID="RFLoginPwd" runat="server" ControlToValidate="texLoginPwd" Display="Dynamic" ErrorMessage="密码不能为空"></asp:RequiredFieldValidator>
                        </td>
					</tr>
                    <tr>
						<td>&nbsp;</td>
						<td></td>
						<td></td>
					</tr>
                    <tr>
						<td style="float:right">验证码：</td>
						<td><asp:TextBox ID="texTest" runat="server" ></asp:TextBox></td>
						<td>
                            <asp:RequiredFieldValidator ID="RFLoginTest" runat="server" ControlToValidate="texTest" Display="Dynamic" ErrorMessage="验证码不能为空"></asp:RequiredFieldValidator>
                        </td>
					</tr>
                	<tr>
						<td>&nbsp;</td>
						<td></td>
						<td></td>
					</tr>
                	<tr>
						<td style="float:right">选择身份</td>
						<td>
                            <asp:RadioButton ID="rbt0" runat="server" GroupName="Type" OnCheckedChanged="rbt0_CheckedChanged" Text="普通用户" />
                            <asp:RadioButton ID="rbt1" runat="server" GroupName="Type" OnCheckedChanged="rbt1_CheckedChanged" Text="管理员" />
						</td>
						<td>&nbsp;</td>
					</tr>
                    <tr>
						<td>&nbsp;</td>
                        <td><asp:Literal ID="ltaInfo" runat="server"></asp:Literal></td>
						<td></td>
					</tr>
					<tr>
						<td></td>
						<td style="align-content:center"><asp:Button ID="btnRegister" runat="server" Text="注册" OnClick="btnRegister_Click" /></td>
						<td></td>
					</tr>
                       
				</tbody>    
        </table>
       


    </center>
</div>
</div>
</asp:Content>
