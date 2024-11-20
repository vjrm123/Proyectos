using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.NetworkInformation;
using System.Text;
using System.Threading.Tasks;

using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace Formulario_CV.Vistas
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class Principal : ContentPage
    {
        

        public Principal()
        {
            InitializeComponent();
        }

        private void btn_datos_personales_Clicked(object sender, EventArgs e)
        {
            Navigation.PushAsync(new Datos_personales());
        }

    }
}