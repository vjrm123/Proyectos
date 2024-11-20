using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace Formulario_CV.Vistas
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class Formulario : ContentPage
    {

        string name;
        string last_name;
        string ocupacion;
        int telefono;
        string Email;
        public Formulario()
        {
            InitializeComponent();
        }

        private void Mostrar()
        {
            Rname.Text = txtname.Text;
            Rlast.Text = txtapellido.Text;
            Rocupacion.Text = txtocupacion.Text;
            Rtelefono.Text = txttelefono.Text;
            Remail.Text = txtemail.Text;
        }
        private void btniniciar_Clicked(object sender, EventArgs e)
        {
            if(Validar())
            {
                Navigation.PushAsync(new CV());
            }
            
        }

        private bool Validar()
        {
            if(string.IsNullOrEmpty(txtname.Text) || string.IsNullOrEmpty(txtapellido.Text)
               || string.IsNullOrEmpty(txtocupacion.Text) || string.IsNullOrEmpty(txttelefono.Text)
               || string.IsNullOrEmpty(txtemail.Text))
            {
                DisplayAlert("Error", "rellene todos los campos","OK");
                return false;
            }
            else
            {
                return true;
            }
        }
        private void Validar_()
        {
            if (string.IsNullOrEmpty(txtname.Text) || string.IsNullOrEmpty(txtapellido.Text)
               || string.IsNullOrEmpty(txtocupacion.Text) || string.IsNullOrEmpty(txttelefono.Text)
               || string.IsNullOrEmpty(txtemail.Text))
            {
                DisplayAlert("Error", "rellene todos los campos", "OK");
            }
            else
            {
                Mostrar();
            }
        }

        private void btnmostrar_Clicked(object sender, EventArgs e)
        {
            Validar_();
        }
    }
}