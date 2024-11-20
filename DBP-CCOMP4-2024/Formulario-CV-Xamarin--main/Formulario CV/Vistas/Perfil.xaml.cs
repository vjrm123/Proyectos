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
    public partial class Perfil : ContentPage
    {

        String names;
        String edads;
        String correos;
        String telefonos;
        String ocupacions;
        String direcions;

        public Perfil(String name, String edad,
            String correo, String telefono, String ocupacion,
            String direcion)
        {
            InitializeComponent();
            names = name;
            edads = edad;
            correos = correo;
            telefonos = telefono;
            ocupacions = ocupacion;
            direcions = direcion;

        }

        string Info_perfil;

        private async void btncompletado_Clicked(object sender, EventArgs e)
        {
            Info_perfil = info_perfil.Text;
            await Navigation.PushAsync(new Idiomas(names, edads,
            correos, telefonos, ocupacions,
            direcions,Info_perfil));
        }
    }

    
}