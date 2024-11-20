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
    public partial class Otros : ContentPage
    {

        String names;
        String edads;
        String correos;
        String telefonos;
        String ocupacions;
        String direcions;
        String info_perfils;
        String info_idiomas;

        public Otros(String name, String edad,
            String correo, String telefono, String ocupacion,
            String direcion, String info_perfil, String idiomas)
        {
            InitializeComponent();
            names = name;
            edads = edad;
            correos = correo;
            telefonos = telefono;
            ocupacions = ocupacion;
            direcions = direcion;
            info_perfils = info_perfil;
            info_idiomas= idiomas;

        }

        string redesxy;
        string educacionxy;
        string experienciaxy;
        string hobbiesxy;

        private async void btncompletado_Clicked(object sender, EventArgs e)
        {

            redesxy = redesx.Text;
            educacionxy = educacionx.Text;
            experienciaxy = experienciax.Text;
            hobbiesxy = hobbiesx.Text;
            await Navigation.PushAsync(new Enviar(names, edads,
            correos, telefonos, ocupacions,
            direcions, info_perfils, info_idiomas, redesxy, educacionxy,
            experienciaxy, hobbiesxy));
        }
    }


}