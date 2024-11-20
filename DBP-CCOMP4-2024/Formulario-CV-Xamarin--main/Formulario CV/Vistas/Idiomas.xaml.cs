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
    public partial class Idiomas : ContentPage
    {

        String names;
        String edads;
        String correos;
        String telefonos;
        String ocupacions;
        String direcions;
        String info_perfils;

        public Idiomas(String name, String edad,
            String correo, String telefono, String ocupacion,
            String direcion, String info_perfil)
        {
            InitializeComponent();
            names = name;
            edads = edad;
            correos = correo;
            telefonos = telefono;
            ocupacions = ocupacion;
            direcions = direcion;
            info_perfils = info_perfil;

        }

        string idiomasxy;

        private async void btncompletado_Clicked(object sender, EventArgs e)
        {

            idiomasxy = idiomasx.Text;
            await Navigation.PushAsync(new Otros(names, edads,
            correos, telefonos, ocupacions,
            direcions, info_perfils,idiomasxy));
        }
    }


}